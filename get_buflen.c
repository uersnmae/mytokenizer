/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_buflen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:46:45 by dong-hki          #+#    #+#             */
/*   Updated: 2025/02/14 13:46:45 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static size_t	normal_state(char **str);
static size_t	single_quote_state(char **str);
static size_t	double_quote_state(char **str);

size_t	get_buflen(char **str)
{
	size_t	len;

	len = 0;
	while (**str && ft_isspace((int)**str))
		++(*str);
	while (**str && ft_isspace((int)**str) == 0)
	{
		if (**str == SINGLE_QUOTE)
		{
			++(*str);
			len = single_quote_state(str);
		}
		else if (**str == DOUBLE_QUOTE)
		{
			++(*str);
			len = double_quote_state(str);
		}
		else
			len = normal_state(str);
	}
	while (**str && ft_isspace((int)**str))
		++(*str);
	return (len);
}

static size_t	normal_state(char **str)
{
	size_t	len;

	len = 0;
	while (**str && !ft_isspace((int)**str))
	{
		if (**str == SINGLE_QUOTE)
		{
			++(*str);
			len += single_quote_state(str);
		}
		else if (**str == DOUBLE_QUOTE)
		{
			++(*str);
			len += double_quote_state(str);
		}
		else
		{
			++len;
			++(*str);
		}
	}
	return (len);
}

static size_t	single_quote_state(char **str)
{
	size_t	len;

	len = 0;
	while (**str)
	{
		if (**str == SINGLE_QUOTE)
		{
			++(*str);
			break ;
		}
		else
		{
			++len;
			++(*str);
		}
	}
	return (len);
}

static size_t	double_quote_state(char **str)
{
	size_t	len;

	len = 0;
	while (**str)
	{
		if (**str == DOUBLE_QUOTE)
		{
			++(*str);
			break ;
		}
		else if (**str == '\\' && (*str + 1))
		{
			(*str) += 2;
			++len;
		}
		else
		{
			++len;
			++(*str);
		}
	}
	return (len);
}
