#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "parser.h"



static parser_t *parser;


int main (int argc, char* argv[]) {
    parser = parser_create(80);

    program(parser);

    parser_destroy(parser);
    exit(0);
}



