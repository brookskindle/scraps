#!/usr/bin/env python3

"""
In python 3 you can force calling a function with keyword arguments.
"""


def print_and_return(
        string,
        *,  # In python3, specifies the end of positional arguments.
        print_str=True,  # Begin the keyword arguments
        second_string,
        return_str=True
        ):
    if print_str:
        print(string)
    print(second_string)
    if return_str:
        return string

f = print_and_return
