#ifndef CMM_AST_H
#define CMM_AST_H

typedef struct AST_STRUCT
{

    enum {
        AST_COMPOUND,
        AST_FUNCTION_DEFINITION,
        AST_VARIABLE,
        AST_STATEMENT,
        AST_NOOP,
        AST_DEFINITION_TYPE
    } type;

} AST_T;

AST_T* init_ast(int type);

#endif