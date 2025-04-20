/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:07:43 by dong-hki          #+#    #+#             */
/*   Updated: 2025/04/21 03:10:44 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static t_toktype	get_operator_len_two(const char **str);
static t_toktype	get_operator_len_one(const char **str);
static t_toktype	get_operator_bonus(const char **str);

t_toktype	get_operator(const char **str)
{
	t_toktype	toktype;

	toktype = get_operator_bonus(str);
	if (toktype != TK_EOF)
		return (toktype);
	toktype = get_operator_len_two(str);
	if (toktype != TK_EOF)
		return (toktype);
	toktype = get_operator_len_one(str);
	if (toktype != TK_EOF)
		return (toktype);
	return (toktype);
}

static t_toktype	get_operator_len_two(const char **str)
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

static t_toktype	get_operator_len_one(const char **str)
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

static t_toktype	get_operator_bonus(const char **str)
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

