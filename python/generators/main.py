#!/usr/bin/env python3

def yield_parenthesis():
    for n in range(5):
        x = (yield n)
        print("Just yielded {}".format(x))

if __name__ == "__main__":
    nums = yield_parenthesis()
    for num in nums:
        print("Received {}".format(num))
        if num % 2 == 1:  # even number
            nums.send("an even number")
