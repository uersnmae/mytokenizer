/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:07:35 by dong-hki          #+#    #+#             */
/*   Updated: 2025/04/21 02:32:28 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (type == TK_EOF || start == NULL || len == 0)
		token->value = NULL;
	else
		token->value = ft_strndup(start, len);
	token->next = NULL;
	return (token);
}

t_toktype	get_operator_len_two(const char **str)
{
	if (**str == '<' && *(*str + 1) == '<')
	{
		*str += 2;
		return (TK_D_REDIR_IN);
	}
	if (**str == '>' && *(*str + 1) == '>')
	{
		*str += 2;
		return (TK_D_REDIR_OUT);
	}
	return (TK_EOF);
}

t_toktype	get_operator_len_one(const char **str)
{
	if (**str == '|')
	{
		(*str)++;
		return (TK_PIPE);
	}
	if (**str == '<')
	{
		(*str)++;
		return (TK_REDIR_IN);
	}
	if (**str == '>')
	{
		(*str)++;
		return (TK_REDIR_OUT);
	}
	return (TK_EOF);
}

t_toktype	get_operator_bonus(const char **str)
{
	if (**str == '|' && *(*str + 1) == '|')
	{
		*str += 2;
		return (TK_OR_IF);
	}
	if (**str == '&' && *(*str + 1) == '&')
	{
		*str += 2;
		return (TK_AND_IF);
	}
	if (**str == '(')
	{
		(*str)++;
		return (TK_LPAR);
	}
	if (**str == ')')
	{
		(*str)++;
		return (TK_RPAR);
	}
	return (TK_EOF);
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
