#include "include/cmm.h"
#include "include/lexer.h"
#include "include/io.h"
#include <stdlib.h>

void cmm_compile(char *src)
{
    lexer_T* lexer = init_lexer(src);
    token_T* tok = 0;

    while ((tok = lexer_next_token(lexer))->type != TOKEN_EOF)
    {
        printf("%s\n", token_to_str(tok));
    }
}

void cmm_compile_file(const char* filename)
{
    char* src = cmm_read_file(filename);
    cmm_compile(src);
    free(src);
}