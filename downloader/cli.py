#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File: cli.py
# Created Date: 2020-08-07
# Author: Rabbit
# --------------------------------
# Copyright (c) 2020 Rabbit

import os
import re
import time
from lxml import etree
import js2py
from .config import DownloaderConfig
from .client import LeetCodeClient
from .template import CppTemplate
from .utils import u
from .const import CACHE_DIR, SUBMISSIONS_DIR

REQUEST_INTERVAL = 2.0

STATUS_SET = set(['Accepted'])

LANG_SETTING = \
{
    "C++": {
        'template': CppTemplate(),
        'file_extension': 'cpp',
    }
}

UNCOMMITED_SUBMISSION_IDS_TXT = os.path.join(CACHE_DIR, "uncommited_sb_ids.txt")
LAST_SUBMISSION_ID_TXT = os.path.join(CACHE_DIR, "last_sb_id.txt")

re_pageData = re.compile(br'var pageData\s*=\s*{.*?};', re.S)
re_filename_invalid_char = re.compile(r'\\|/|:|\*|\?|"|<|>|\|')


def task_login(client):

    if client.logged_in:
        print("Use cached session")
        return

    print("Login to LeetCode")

    r = client.github_login()
    r.raise_for_status()

    tree = etree.HTML(r.content)

    inputs = tree.xpath('//div[contains(@class, "auth-form")]//input')
    data = { inp.get('name'): inp.get('value') for inp in inputs }
    referer = r.url

    r = client.github_session(data, referer)
    r.raise_for_status()

    tree = etree.HTML(r.content)
    url = tree.xpath('.//a[@id="js-manual-authorize-redirect"]/@href')[0]

    r = client.authorize_redirect(url)
    r.raise_for_status()


def task_download_submissions(client):

    last_sb_id = -1
    uncommited_sbs = set()

    if os.path.exists(LAST_SUBMISSION_ID_TXT):
        with open(LAST_SUBMISSION_ID_TXT, 'r', encoding='utf-8-sig') as fp:
            last_sb_id = int(fp.read())

    print("Last submission ID: %d" % last_sb_id)

    if os.path.exists(UNCOMMITED_SUBMISSION_IDS_TXT):
        with open(UNCOMMITED_SUBMISSION_IDS_TXT, 'r', encoding='utf-8-sig') as fp:
            uncommited_sbs.update([ int(sb_id) for sb_id in fp ])
        print("Found %d uncommited submissions" % len(uncommited_sbs))

    offset = 0
    limit = 20
    has_next = True
    last_key = ''
    finished = False
    new_last_sb_id = last_sb_id

    while has_next and not finished:

        print("GET submissions list %d-%d" % (offset, offset + limit))

        r = client.submissions_list(offset, limit, last_key)
        r.raise_for_status()

        offset += limit

        print("Done. Sleep %s seconds" % REQUEST_INTERVAL)
        time.sleep(REQUEST_INTERVAL)

        rjson = r.json()

        has_next = rjson['has_next']
        last_key = rjson['last_key']

        for sb in rjson['submissions_dump']:

            sb_id = sb['id']
            status = sb['status_display']
            lang = sb['lang']
            title = sb['title']

            if sb_id <= last_sb_id:
                print("Finishied")
                finished = True
                break

            if sb['is_pending'] != 'Not Pending':
                continue

            if status not in STATUS_SET:
                continue

            setting = LANG_SETTING.get(lang)

            if setting is None:
                continue

            new_last_sb_id = max(new_last_sb_id, sb_id)

            if sb_id in uncommited_sbs:
                print("GET submission %d from uncommited submissions" % sb_id)
                continue

            template = setting['template']
            ext = setting['file_extension']

            print("GET submission %d" % sb_id)

            r = client.submissions_detail(sb['url'])
            r.raise_for_status()

            mat = re_pageData.search(r.content)
            assert mat is not None

            js_code = u(mat.group())
            data = js2py.eval_js(js_code)

            q_id = data.questionId

            code = template.render(
                sb_id=sb_id,
                q_id=q_id,
                q_url=data.editCodeUrl,
                q_title=title,
                a_time=sb['timestamp'],
                a_test_correct=data.submissionData.total_correct,
                a_test_total=data.submissionData.total_testcases,
                a_status=status,
                a_memory=sb['memory'],
                a_runtime=sb['runtime'],
                a_code=data.submissionCode,
            )

            filename = '%s-%s-%d.%s' % (
                re_filename_invalid_char.sub('_', q_id),
                re_filename_invalid_char.sub('_', title),
                sb_id,
                ext
            )

            filepath = os.path.join(SUBMISSIONS_DIR, filename)

            with open(filepath, 'w', encoding='utf-8-sig') as fp:
                fp.write(code)

            uncommited_sbs.add(sb_id)

            with open(UNCOMMITED_SUBMISSION_IDS_TXT, 'a', encoding='utf-8-sig') as fp:
                print(sb_id, file=fp)

            print("Done. Sleep %s seconds" % REQUEST_INTERVAL)
            time.sleep(REQUEST_INTERVAL)

    print("Current last submission ID: %d" % new_last_sb_id)

    with open(LAST_SUBMISSION_ID_TXT, 'w', encoding='utf-8-sig') as fp:
        print(new_last_sb_id, file=fp)

    if os.path.exists(UNCOMMITED_SUBMISSION_IDS_TXT):
        os.remove(UNCOMMITED_SUBMISSION_IDS_TXT)


def main():

    config = DownloaderConfig()
    client = LeetCodeClient(
        github_username=config.github_username,
        github_password=config.github_password,
    )

    task_login(client)
    task_download_submissions(client)
