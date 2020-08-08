#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File: test_client.py
# Created Date: 2020-08-07
# Author: Rabbit
# --------------------------------
# Copyright (c) 2020 Rabbit

import sys
sys.path.append('../')

import os
import re
import time
from pprint import pprint
from lxml import etree
import js2py
from downloader.config import DownloaderConfig
from downloader.client import LeetCodeClient
from downloader.template import CppTemplate
from downloader.utils import u
from downloader.const import SUBMISSIONS_DIR
from downloader.debug import dump_response_content, download_static,\
    print_client_cookies, print_request, print_response

def download_js():
    download_static('https://github.githubassets.com/assets/frameworks-56dcc397.js')


def test_login(client: LeetCodeClient):

    if client.logged_in:
        return

    r = client.github_login()
    r.raise_for_status()

    dump_response_content(r, "github_login.html")
    # pprint(r.__dict__)
    # print_client_cookies(client)

    tree = etree.HTML(r.content)

    inputs = tree.xpath('//div[contains(@class, "auth-form")]//input')
    data = { inp.get('name'): inp.get('value') for inp in inputs }
    referer = r.url

    r = client.github_session(data, referer)
    r.raise_for_status()

    # dump_response_content(r, "github_session.html")
    # pprint(r.__dict__)
    # print_client_cookies(client)

    tree = etree.HTML(r.content)
    url = tree.xpath('.//a[@id="js-manual-authorize-redirect"]/@href')[0]

    r = client.authorize_redirect(url)
    r.raise_for_status()

    # dump_response_content(r, "authorize_redirect.html")
    # pprint(r.__dict__)


def test_download_submissions(client):

    request_interval = 2.0

    status_set = set(['Accepted'])

    lang_setting = {
        "C++": {
            'template': CppTemplate(),
            'file_extension': 'cpp',
        }
    }

    re_pageData = re.compile(br'var pageData\s*=\s*{.*?};', re.S)
    re_filename = re.compile(r'^([^-]+)-(.*?)-(\d+)\.(\S+)$')
    re_filename_invalid_char = re.compile(r'\\|/|:|\*|\?|"|<|>|\|')

    last_sb_id = -1

    for filename in os.listdir(SUBMISSIONS_DIR):
        mat = re_filename.match(filename)
        assert mat is not None
        sb_id = int(mat.group(3))
        last_sb_id = max(last_sb_id, sb_id)

    offset = 0
    limit = 20
    has_next = True
    last_key = ''

    while has_next:

        print("GET submissions list %s-%s" % (offset, offset + limit))

        r = client.submissions_list(offset, limit, last_key)
        r.raise_for_status()

        offset += limit

        # dump_response_content(r, "submissions_list.json")

        print("Done. Sleep %s seconds" % request_interval)
        time.sleep(request_interval)

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
                return

            if sb['is_pending'] != 'Not Pending':
                continue

            if status not in status_set:
                continue

            setting = lang_setting.get(lang)

            if setting is None:
                continue

            template = setting['template']
            ext = setting['file_extension']

            print("GET submission %s" % sb_id)

            r = client.submissions_detail(sb['url'])
            r.raise_for_status()

            # dump_response_content(r, "submission_%s.html" % sbid)

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

            filename = '%s-%s-%s.%s' % (
                re_filename_invalid_char.sub('_', q_id),
                re_filename_invalid_char.sub('_', title),
                sb_id,
                ext
            )

            filepath = os.path.join(SUBMISSIONS_DIR, filename)

            with open(filepath, 'w', encoding='utf-8') as fp:
                fp.write(code)

            print("Done. Sleep %s seconds" % request_interval)
            time.sleep(request_interval)


def main():

    config = DownloaderConfig()
    client = LeetCodeClient(
        github_username=config.github_username,
        github_password=config.github_password,
    )

    # download_js()
    test_login(client)
    test_download_submissions(client)


if __name__ == "__main__":
    main()
