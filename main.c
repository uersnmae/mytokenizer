#include <stdio.h>
#include "tokenizer.h"

int main(int argc, char **argv)
{
	char	**token;

	token = NULL;
	if (argc > 1)
	{
		token = tokenizer(argv[1], token_count(argv[1]));
		for (int i = 0; token[i]; i++)
		{
			printf("token %d: %s\n", i, token[i]);
			free(token[i]);
		}
	}
	free(token);
	return (0);
}
