#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File: const.py
# Created Date: 2020-08-07
# Author: Rabbit
# --------------------------------
# Copyright (c) 2020 Rabbit

from ._internal import absp, mkdir

CACHE_DIR = absp("../cache/")
SUBMISSIONS_DIR = absp("../submissions")
CONFIG_INI = absp("../config.ini")

mkdir(CACHE_DIR)
mkdir(SUBMISSIONS_DIR)
