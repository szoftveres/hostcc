# hostcc
Native C-like compiler

```
./b ./unix_prog.c
echo -n Hello World | ./unix_prog.bin /bin/ls -l ./unix_prog.bin
```
See [x86_64_Linux/header.s](https://github.com/szoftveres/hostcc/blob/master/compiler/arch/x86_64_Linux/header.s) for implemented system calls,
and [unix_routines.c](https://github.com/szoftveres/hostcc/blob/master/unix_routines.c) for helper functions.

