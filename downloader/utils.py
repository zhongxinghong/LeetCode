#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File: utils.py
# Created Date: 2020-08-07
# Author: Rabbit
# --------------------------------
# Copyright (c) 2020 Rabbit

import pickle
import gzip

def b(s, encoding="utf-8"):
    """ str/int/float to bytes """
    if isinstance(s, bytes):
        return s
    if isinstance(s, (str, int ,float)):
        return str(s).encode(encoding)
    raise TypeError("unsupported type %s of %r" % (s.__class__.__name__, s))

def u(s, encoding="utf-8"):
    """ bytes/int/float to str """
    if isinstance(s, (str, int, float)):
        return str(s)
    if isinstance(s, bytes):
        return s.decode(encoding)
    raise TypeError("unsupported type %s of %r" % (s.__class__.__name__, s))

def pgz_dump(obj, file):
    with gzip.open(file, 'wb') as fp:
        pickle.dump(obj, fp)

def pgz_load(file):
    with gzip.open(file, 'rb') as fp:
        return pickle.load(fp)

class Singleton(type):

    _inst = {}

    def __call__(cls, *args, **kwargs):
        if cls not in cls._inst:
            cls._inst[cls] = super(Singleton, cls).__call__(*args, **kwargs)
        return cls._inst[cls]
