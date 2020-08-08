#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File: config.py
# Created Date: 2020-08-07
# Author: Rabbit
# --------------------------------
# Copyright (c) 2020 Rabbit

from configparser import RawConfigParser
from .const import CONFIG_INI
from .utils import Singleton

class BaseConfig(object):

    def __init__(self, config_file=None):
        self._config = RawConfigParser()
        self._config.read(config_file, encoding="utf-8-sig")

    def get(self, section, key):
        return self._config.get(section, key)

    def getint(self, section, key):
        return self._config.getint(section, key)

    def getfloat(self, section, key):
        return self._config.getfloat(section, key)

    def getboolean(self, section, key):
        return self._config.getboolean(section, key)

class DownloaderConfig(BaseConfig, metaclass=Singleton):

    def __init__(self, config_file=CONFIG_INI):
        super().__init__(config_file=config_file)

    @property
    def github_username(self):
        return self._config.get('github', 'username')

    @property
    def github_password(self):
        return self._config.get('github', 'password')
