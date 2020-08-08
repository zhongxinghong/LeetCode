#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File: client.py
# Created Date: 2020-08-07
# Author: Rabbit
# --------------------------------
# Copyright (c) 2020 Rabbit

import os
import base64
from requests import Session
from .cache import LeetCodeClientCache
from .utils import b, u, pgz_dump, pgz_load
from .const import CACHE_DIR

class LeetCodeClient(object):

    def __init__(self, github_username, github_password, timeout=15):
        self._github_username = github_username
        self._github_password = github_password
        self._timeout = timeout

        cache_key = u(base64.b64encode(b("github$%s" % github_username)).rstrip(b'='))
        self._cache_file = os.path.join(CACHE_DIR, "%s_session.gz" % cache_key)
        self._logged_in = False

        self._session = Session()
        self._session.headers.update({
            "accept-encoding": "gzip, deflate, br",
            "accept-language": "en-US,en;q=0.9",
            "cache-control": "no-cache",
            "pragma": "no-cache",
            "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.105 Safari/537.36",
        })

        if os.path.exists(self._cache_file):
            cache = pgz_load(self._cache_file)
            if not cache.is_expired:
                self._session.cookies = cache.cookies
                self._logged_in = True

    @property
    def logged_in(self):
        return self._logged_in

    def close(self):
        self._session.close()

    def _request(self, method, url, params=None, data=None, **kwargs):
        kwargs.setdefault("timeout", self._timeout)
        return self._session.request(method, url, params=params, data=data, **kwargs)

    def _get(self, url, params=None, **kwargs):
        return self._request('GET', url, params=params, **kwargs)

    def _post(self, url, data=None, **kwargs):
        return self._request('POST', url, data=data, **kwargs)

    def github_login(self):
        r = self._get(
            url='https://leetcode-cn.com/accounts/github/login',
            headers={
                "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
                "referer": "https://leetcode-cn.com/problemset/all/",
                "sec-fetch-dest": "document",
                "sec-fetch-mode": "navigate",
                "sec-fetch-site": "same-origin",
                "sec-fetch-user": "?1",
                "upgrade-insecure-requests": "1",
            },
            params={
                'next': '/problemset/all/'
            }
        )
        return r

    def github_session(self, data, referer):

        required_keys = ['commit', 'authenticity_token', 'return_to', 'timestamp',
                         'timestamp_secret'] # , 'required_field_xxxx',

        assert all( k in data for k in required_keys )

        data['login'] = self._github_username
        data['password'] = self._github_password
        data['webauthn-support'] = 'supported'
        data['webauthn-iuvpaa-support'] = 'unsupported'

        # we ignore 'ga_id' field

        r = self._post(
            url='https://github.com/session',
            headers={
                "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
                "Host": "github.com",
                "Origin": "https://github.com",
                "Referer": referer,
                "Sec-Fetch-Dest": "document",
                "Sec-Fetch-Mode": "navigate",
                "Sec-Fetch-Site": "same-origin",
                "Sec-Fetch-User": "?1",
                "Upgrade-Insecure-Requests": "1",
            },
            data=data
        )
        return r

    def authorize_redirect(self, url):
        r = self._get(
            url=url,
            headers={
                "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
                "referer": "https://github.com/",
                "sec-fetch-dest": "document",
                "sec-fetch-mode": "navigate",
                "sec-fetch-site": "cross-site",
                "upgrade-insecure-requests": "1",
            }
        )

        if r.ok:
            self._logged_in = True
            cache = LeetCodeClientCache(self._session.cookies)
            pgz_dump(cache, self._cache_file)

        return r

    def submissions_list(self, offset, limit, lastkey):
        r = self._get(
            url='https://leetcode-cn.com/api/submissions/',
            headers={
                "accept": "*/*",
                "referer": "https://leetcode-cn.com/submissions/",
                "sec-fetch-dest": "empty",
                "sec-fetch-mode": "cors",
                "sec-fetch-site": "same-origin",
                "x-requested-with": "XMLHttpRequest",
            },
            params={
                "offset": offset,
                "limit": limit,
                "lastkey": lastkey,
            }
        )
        return r

    def submissions_detail(self, url):
        r = self._get(
            url='https://leetcode-cn.com' + url,
            headers={
                "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
                "referer": "https://leetcode-cn.com/submissions/",
                "sec-fetch-dest": "document",
                "sec-fetch-mode": "navigate",
                "sec-fetch-site": "same-origin",
                "sec-fetch-user": "?1",
                "upgrade-insecure-requests": "1",
            }
        )
        return r
