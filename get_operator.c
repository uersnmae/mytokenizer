/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:06:45 by dong-hki          #+#    #+#             */
/*   Updated: 2025/04/21 03:07:30 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

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
