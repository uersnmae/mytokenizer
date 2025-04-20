/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:06:45 by dong-hki          #+#    #+#             */
/*   Updated: 2025/04/21 03:13:51 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_toktype	get_operator_len_two(const char **str);
t_toktype	get_operator_len_one(const char **str);

t_toktype	get_operator(const char **str)
{
	t_toktype	toktype;

	toktype = get_operator_len_two(str);
	if (toktype != TK_EOF)
		return (toktype);
	toktype = get_operator_len_one(str);
	if (toktype != TK_EOF)
		return (toktype);
	return (toktype);
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
