#!/usr/bin/env python
"""
There are often multiple ways of doing the same thing in python.

Besides syntax, what is the difference between, say, list comprehension and a
for loop?

We can use the builtin dis module to disassemble the code of two equivalent
functions to determine this.
"""

import dis

def c_range(n: int) -> list:
    ret = [x for x in range(n)]
    return ret


def f_range(n: int) -> list:
    ret = []
    for i in range(n):
        ret.append(i)
    return ret

if __name__ == "__main__":
    print("Disassembling a function with a list comprehension")
    print("="*40+"bytecode"+"="*40)
    print(c_range.__code__.co_code)
    print("-"*40+"disassembled"+"-"*40)
    dis.dis(c_range)

    print("\n\n")

    print("Disassembling a function with a for loop")
    print("="*40+"bytecode"+"="*40)
    print(f_range.__code__.co_code)
    print("-"*40+"disassembled"+"-"*40)
    dis.dis(f_range)
