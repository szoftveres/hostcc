#define NULL        (0)
#define MINUS_ONE   (0xFFFFFFFF)
#define EOF         MINUS_ONE

#define PROT_READ        (0x1)
#define PROT_WRITE       (0x2)

#define MAP_PRIVATE      (0x02)
#define MAP_ANONYMOUS    (0x20)


/* Get argument */
getargaddr (argv, arg) {
    argv + (arg * sizeof());
}

getarg (argv, arg) {
    *getargaddr(argv, arg);
}

/* Write 1 char to stdout */
putchar (c) {
    write(1, &c, 1);
}

/* Get 1 char from stdin */
getchar () {
    auto c;
    c = 0;
    if (!read(0, &c, 1)) {
        c = EOF;
    }
    c;
}

/* Print unsigned decimal integer */
putd (num) {
    if(num / 10){
        putd(num / 10);
    }
    putchar((num % 10) + '0');
}

putx_internal (num) {
    if (num / 0x10) {
        putx_internal(num / 0x10);
    }
    putchar((num % 0x10) + (((num % 0x10) >= 10) ? ('a' - 10) : ('0')));
}

/* Print hexadecimal integer */
putx (num) {
   putchar('0');
   putchar('x');
   putx_internal(num);
}

/* Print string */
puts (s) {
    while (*s & 0xFF) {
        putchar(*s & 0xFF);
        s += 1;
    }
}

waitpid (pid, status_p) {
    wait4(pid, status_p, 0, 0);
}

wait (status_p) {
    wait4(MINUS_ONE, status_p, 0, 0);
}

execv (path, argv) {
    execve(path, argv, NULL);
}

malloc (size) {
    auto p;
    p = mmap(NULL, size,
         PROT_READ | PROT_WRITE,
         MAP_PRIVATE | MAP_ANONYMOUS, MINUS_ONE, 0);
    p < 0 ? 0 : p;
}

free (p) {
    munmap(p, 0);
}


memset (addr, value, length) {
    while ((length >= 0) & length) {
        *(addr) = value;
        length -= 8;
        addr += 8;
    }
}

/*
atoi (s) {
    auto n;
    auto valid;

    n = 0;
    valid = 0;

    while (s) {
        if ((*s & 0xFF) >= '0') {
            if ()
        }
    }
}
*/
