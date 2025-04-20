
#include <stdio.h>
#include "tokenizer.h"

const char *toktype_str[] = {
    [TK_WORD] = "WORD",
    [TK_PIPE] = "PIPE",
    [TK_REDIR_IN] = "REDIR_IN",
    [TK_REDIR_OUT] = "REDIR_OUT",
    [TK_D_REDIR_IN] = "D_REDIR_IN",
    [TK_D_REDIR_OUT] = "D_REDIR_OUT",
    [TK_LPAR] = "LPAR",
    [TK_RPAR] = "RPAR",
    [TK_AND_IF] = "AND_IF",
    [TK_OR_IF] = "OR_IF",
    [TK_EOF] = "EOF"
};

int main(void)
{
    char input[1024];
    printf("Enter a minishell command line:\n> ");
    if (!fgets(input, sizeof(input), stdin))
        return 1;

    t_token *tokens = tokenize(input);
    for (t_token *tok = tokens; tok; tok = tok->next)
    {
        const char *type_str = toktype_str[tok->type];
        if (tok->value)
            printf("[%-10s] \"%s\"\n", type_str, tok->value);
        else
            printf("[%-10s] (no value)\n", type_str);
    }
    free_tokens(tokens);
    return 0;
}
