From http://www.thegeekstuff.com/2012/03/reverse-engineering-tools/

LD_PRELOAD

Allow you to intercept library calls and use your own functions in their place.

To perform this trick, first compile main.c with
```bash
gcc main.c
```

Simply executing `a.out` will give a non-matching string output (as it should).
However, if we want to trick the program into thinking that strcmp actually
matched, we can compile our own version of the `strcmp` function and trick the
program into using our version instead.

```bash
gcc strcmp.c -o mystrcmp.so -ldl -shared
```

With the strcmp function being compiled as a shared library, we can use the
`LD_PRELOAD` environment variable to allow `a.out` to gain access to our
library.

NOTE: LD_PRELOAD expects the path to the shared library object to be a full
path.

```bash
LD_PRELOAD=$(pwd -P)/mystrcmp.so ./a.out
```

Pretty cool eh?
