/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:07:52 by dong-hki          #+#    #+#             */
/*   Updated: 2025/02/14 11:53:11 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_state		init_state(char **argv);
static void	normal_state(char **argv, int *count, t_state *curr_state);
static void	single_quote_state(char **argv, int *count, t_state *curr_state);
static void	double_quote_state(char **argv, int *count, t_state *curr_state);

int	token_count(char *argv)
{
	t_state	curr_state;
	int		count;
	char	*p_argv;

	p_argv = argv;
	curr_state = init_state(&p_argv);
	count = 0;
	while (*p_argv)
	{
		if (curr_state == STATE_NORMAL)
			normal_state(&p_argv, &count, &curr_state);
		else if (curr_state == STATE_SINGLE_QUOTE)
			single_quote_state(&p_argv, &count, &curr_state);
		else if (curr_state == STATE_DOUBLE_QUOTE)
			double_quote_state(&p_argv, &count, &curr_state);
	}
	return (count);
}

t_state	init_state(char **argv)
{
	while (ft_isspace((int)**argv) && **argv)
		++(*argv);
	if (**argv == SINGLE_QUOTE)
		return (STATE_SINGLE_QUOTE);
	if (**argv == DOUBLE_QUOTE)
		return (STATE_DOUBLE_QUOTE);
	return (STATE_NORMAL);
}

static void	normal_state(char **argv, int *count, t_state *curr_state)
{
	while (**argv)
	{
		if (ft_isspace((int)**argv) || (**argv) == '\0')
		{
			while (ft_isspace((int)**argv) && **argv)
				++(*argv);
			++(*count);
		}
		else if (**argv == SINGLE_QUOTE)
		{
			*curr_state = STATE_SINGLE_QUOTE;
			++(*argv);
		}
		else if (**argv == DOUBLE_QUOTE)
		{
			*curr_state = STATE_DOUBLE_QUOTE;
			++(*argv);
		}
		else
			++(*argv);
		if (*curr_state != STATE_NORMAL)
			break ;
	}
}

static void	single_quote_state(char **argv, int *count, t_state *curr_state)
{
	while (**argv)
	{
		if (**argv == SINGLE_QUOTE)
		{
			*curr_state = STATE_NORMAL;
			++(*argv);
			++(*count);
			while (ft_isspace((int)(**argv)) && **argv)
				++(*argv);
			return ;
		}
		else
			++(*argv);
	}
}

static void	double_quote_state(char **argv, int *count, t_state *curr_state)
{
	while (**argv)
	{
		if (**argv == DOUBLE_QUOTE)
		{
			*curr_state = STATE_NORMAL;
			++(*count);
			++(*argv);
			while (ft_isspace((int)(**argv)) && **argv)
				++(*argv);
			return ;
		}
		++(*argv);
	}
}
