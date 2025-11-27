#include "unix_std.c"



fibonacci (n) {
    if (n < 2) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  /* Arbitrary deep recursion */
}



main (argc, argv) {
    auto i;
    auto c;
    auto i_p;

    for (i = 0; i != 20; i += 1) {
        puts("For World!  "); putd(fibonacci(i)); puts("\n");
    }

    i_p = &i;
    i = 0;
    *i_p = 10;
    while (i) {
        switch (*i_p) {
          case 3:
          case 6:
            puts("While World! 3,6 "); putd(fibonacci(i)); puts("\n");
            break;
          default:
            puts("While World!  "); putd(fibonacci(i)); puts("\n");
            break;
        }
        i -= 1;
    }

    0; /* return code of 'main' is the exit code of the program */
}

