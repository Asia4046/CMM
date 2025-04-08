#include "include/parser.h"
#include <stdlib.h>
#include "include/AST.h"

parser_T* init_parser(lexer_T* lexer)
{
    parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));

    parser->lexer = lexer;
    parser->token = lexer_next_token(lexer);

    return parser;
}

token_T* parser_eat(parser_T* parser, int type)
{
    if(parser->token->type != type)
    {
        printf("[CMM_PARSER]: Unexpected token: `%s`, was expecting: `%s`\n", token_to_str(parser->token), token_type_to_str(type));
        exit(1);
    }

    parser->token = lexer_next_token(parser->lexer);
    return parser->token;
}

AST_T* parser_parse(parser_T* parser)
{
    return parser_parse_compound(parser);
}

AST_T* parser_parse_compound(parser_T* parser)
{
    AST_T* compound = init_ast(AST_COMPOUND);

    while(parser->token->type != TOKEN_EOF)
    {

         list_push(compound->children, parser_parse(parser));
    }

    return compound;
}