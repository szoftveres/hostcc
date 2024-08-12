#include "unix_std.c"

#define PRIMES    (65536)

#define GET_BIT(n)     (   *(array + ((n)>>6)) & (1<<((n) & 63))   )
#define SET_BIT(n)     *(array + ((n)>>6)) |= (1<<((n) & 63))


main (argc, argv) {
    auto n;
    auto c;
    auto array;

    c = 0;

    puts("Hello World!\n");

    array = malloc(PRIMES/8); /* this is in bytes */

    memset(array, 0x00, PRIMES/8);

    putx(array);
    puts("\n");

    for (n = 2; n < PRIMES; n += 1) {

        puts("testing: "); putd(n); puts("\n");
        if (!GET_BIT(n)) {
            auto p;
            puts("prime: "); putd(n); puts("\n");
            c += 1;

            if (n < 256) {
                for (p = n; p < PRIMES; p += n) {
                    SET_BIT(p);
                    puts("setting: "); putd(p); puts("\n");
                }
            }
        }

    }
    puts("count: "); putd(c); puts("\n");

    0; /* return code of 'main' is the exit code of the program */
}

