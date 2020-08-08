#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File: cache.py
# Created Date: 2020-08-07
# Author: Rabbit
# --------------------------------
# Copyright (c) 2020 Rabbit

import time

class LeetCodeClientCache(object):

    def __init__(self, cookies, expires=3600 * 24 * 7):
        self._cookies = cookies
        self._expired_time = int(time.time()) + expires

    @property
    def cookies(self):
        return self._cookies

    @property
    def is_expired(self):
        return self._expired_time < int(time.time())
