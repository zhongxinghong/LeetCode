#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File: template.py
# Created Date: 2020-08-07
# Author: Rabbit
# --------------------------------
# Copyright (c) 2020 Rabbit

import time

class CppTemplate(object):

    def __init__(self):
        self._leetcode_base_url = 'https://leetcode-cn.com'

    def _format_timestamp(self, timestamp):
        return time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(int(timestamp)))

    def render(self, sb_id, q_id, q_url, q_title, a_time, a_test_correct,
               a_test_total, a_status, a_memory, a_runtime, a_code):
        sbuf = []
        sbuf.append('/**')
        sbuf.append(' * Submission ID: %s' % sb_id)
        sbuf.append(' * Question ID: %s' % q_id)
        sbuf.append(' * Question Title: %s' % q_title)
        sbuf.append(' * Question URL: %s' % (self._leetcode_base_url + q_url))
        sbuf.append(' * Solution Time: %s' % self._format_timestamp(a_time))
        sbuf.append(' * Solution Test Result: %s / %s' % (a_test_correct, a_test_total))
        sbuf.append(' * Solution Status: %s' % a_status)
        sbuf.append(' * Solution Memory: %s' % a_memory)
        sbuf.append(' * Solution Runtime: %s' % a_runtime)
        sbuf.append(' */')
        sbuf.append('')
        sbuf.extend([ line.rstrip() for line in a_code.strip().splitlines() ])
        sbuf.append('')
        return '\n'.join(sbuf)
