#include "include/cmm.h"
#include "include/lexer.h"
#include "include/io.h"
#include "include/AST.h"
#include "include/parser.h"
#include <stdlib.h>

void cmm_compile(char *src)
{
    lexer_T* lexer = init_lexer(src);
    parser_T* parser = init_parser(lexer);
    AST_T* root = parser_parse(parser);

     printf("%d\n", root->children->size);

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