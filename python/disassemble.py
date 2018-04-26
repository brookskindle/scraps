#!/usr/bin/env python
"""
There are often multiple ways of doing the same thing in python.

Besides syntax, what is the difference between, say, list comprehension and a
for loop?

We can use the builtin dis module to disassemble the code of two equivalent
functions to determine this.
"""

import dis

def comprehension(n: int) -> list:
    ret = [x for x in range(n)]
    return ret


def forloop(n: int) -> list:
    ret = []
    for i in range(n):
        ret.append(i)
    return ret


print("Disassembling a function with a list comprehension")
print("="*40+"bytecode"+"="*40)
print(comprehension.__code__.co_code)
print("-"*40+"disassembled"+"-"*40)
dis.dis(comprehension)

print("\n\n")

print("Disassembling a function with a for loop")
print("="*40+"bytecode"+"="*40)
print(forloop.__code__.co_code)
print("-"*40+"disassembled"+"-"*40)
dis.dis(forloop)

# OUTPUT BELOW HERE
"""
Disassembling a function with a list comprehension
========================================bytecode========================================
b'd\x01\x00d\x02\x00\x84\x00\x00t\x00\x00|\x00\x00\x83\x01\x00D\x83\x01\x00}\x01\x00|\x01\x00S'
----------------------------------------disassembled----------------------------------------
 15           0 LOAD_CONST               1 (<code object <listcomp> at 0x7fb5a9edc930, file "disassemble.py", line 15>)
              3 LOAD_CONST               2 ('comprehension.<locals>.<listcomp>')
              6 MAKE_FUNCTION            0
              9 LOAD_GLOBAL              0 (range)
             12 LOAD_FAST                0 (n)
             15 CALL_FUNCTION            1 (1 positional, 0 keyword pair)
             18 GET_ITER
             19 CALL_FUNCTION            1 (1 positional, 0 keyword pair)
             22 STORE_FAST               1 (ret)

 16          25 LOAD_FAST                1 (ret)
             28 RETURN_VALUE



Disassembling a function with a for loop
========================================bytecode========================================
b'g\x00\x00}\x01\x00x!\x00t\x00\x00|\x00\x00\x83\x01\x00D]\x13\x00}\x02\x00|\x01\x00j\x01\x00|\x02\x00\x83\x01\x00\x01q\x13\x00W|\x01\x00S'
----------------------------------------disassembled----------------------------------------
 20           0 BUILD_LIST               0
              3 STORE_FAST               1 (ret)

 21           6 SETUP_LOOP              33 (to 42)
              9 LOAD_GLOBAL              0 (range)
             12 LOAD_FAST                0 (n)
             15 CALL_FUNCTION            1 (1 positional, 0 keyword pair)
             18 GET_ITER
        >>   19 FOR_ITER                19 (to 41)
             22 STORE_FAST               2 (i)

 22          25 LOAD_FAST                1 (ret)
             28 LOAD_ATTR                1 (append)
             31 LOAD_FAST                2 (i)
             34 CALL_FUNCTION            1 (1 positional, 0 keyword pair)
             37 POP_TOP
             38 JUMP_ABSOLUTE           19
        >>   41 POP_BLOCK

 23     >>   42 LOAD_FAST                1 (ret)
             45 RETURN_VALUE
"""
