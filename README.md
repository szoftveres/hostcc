# hostcc
Native C-like compiler
Uses [mcc](https://github.com/szoftveres/mcc).

```
./b ./program.c
echo -n Hello World | ./program.bin /bin/ls -l
```
See [x86_64_Linux/header.s](https://github.com/szoftveres/hostcc/blob/master/compiler/arch/x86_64_Linux/header.s) for implemented system calls,
and [unix_std.c](https://github.com/szoftveres/hostcc/blob/master/unix_std.c) for helper functions.

