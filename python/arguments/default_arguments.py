#!/usr/bin/env python

"""
Apparently default arguments are set at module load time, so any subsequent
calls to bad_default_args will reference the same list_ for the default
argument.
"""

def bad_default_args(list_=[]):
    list_.append(1)
    return list_

f = bad_default_args
