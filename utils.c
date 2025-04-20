/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:06:31 by dong-hki          #+#    #+#             */
/*   Updated: 2025/04/21 03:07:32 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft/libft.h"
#include "tokenizer.h"

int	is_operator_start(char c)
{
	return (c == '|' || c == '<' || c == '>' || \
	c == '(' || c == ')');
}

t_token	*get_new_token(t_toktype type, const char *start, size_t len)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = type;
	token->token_size = (int)len;
	if (type == TK_EOF || start == NULL || len == 0)
		token->value = NULL;
	else
		token->value = ft_strndup(start, len);
	token->next = NULL;
	return (token);
}

void	free_tokens(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->value);
		free(tmp);
	}
}
