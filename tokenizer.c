/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:43:02 by dong-hki          #+#    #+#             */
/*   Updated: 2025/04/21 02:29:41 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tokenizer.h"

static void			parse_quote(const char **p_input, t_token **head, t_token **tail);
static void			parse_operator(const char **p_input, t_token **head, t_token **tail);
static void			parse_word(const char **p_input, t_token **head, t_token **tail);
static t_toktype	get_operator(const char **str);
static void			parse_eof(t_token **head, t_token **tail);

t_token	*tokenize(const char *input)
{
	const char	*p_input = input;
	t_token		*head;
	t_token		*tail;

	head = NULL;
	tail = NULL;
	while (*p_input)
	{
		while (ft_isspace(*p_input))
			p_input++;
		if (*p_input == '\'' || *p_input == '"')
			parse_quote(&p_input, &head, &tail);
		else if (is_operator_start(*p_input))
			parse_operator(&p_input, &head, &tail);
		else if (*p_input)
			parse_word(&p_input, &head, &tail);
	}
	parse_eof(&head, &tail);
	return (head);
}

static t_toktype	get_operator(const char **str)
{
	t_toktype	toktype;

	toktype = get_operator_len_two(str);
	if (toktype != TK_EOF)
		return (toktype);
	toktype = get_operator_len_one(str);
	return (toktype);
}

static void	parse_quote(const char **p_input, t_token **head, t_token **tail)
{
	const char	*start = *p_input + 1;
	char		quote;
	t_token		*token;

	quote = *(*p_input)++;
	while (**p_input && **p_input != quote)
	{
		if (quote == '"' && **p_input == '\\' && *(*p_input + 1))
			(*p_input)++;
		(*p_input)++;
	}
	if (**p_input == quote)
		(*p_input)++;
	token = get_new_token(TK_WORD, start, *p_input - start);
	if (token == NULL)
		return ;
	if (*head == NULL)
		*head = token;
	else
		(*tail)->next = token;
	*tail = token;
}

static void	parse_operator(const char **p_input, t_token **head, t_token **tail)
{
	const char	*start = *p_input;
	t_toktype	toktype;
	t_token		*token;

	toktype = get_operator(p_input);
	token = get_new_token(toktype, start, *p_input - start);
	if (token == NULL)
		return ;
	if (*head == NULL)
		*head = token;
	else
		(*tail)->next = token;
	*tail = token;
}

static void	parse_word(const char **p_input, t_token **head, t_token **tail)
{
	const char	*start = *p_input;
	t_token		*token;

	while (**p_input \
		&& ft_isspace(**p_input) == 0
		&& is_operator_start(**p_input) == 0 \
		&& **p_input != '\'' \
		&& **p_input != '"')
	{
		(*p_input)++;
	}
	token = get_new_token(TK_WORD, start, *p_input - start);
	if (token == NULL)
		return ;
	if (*head == NULL)
		*head = token;
	else
		(*tail)->next = token;
	*tail = token;
}

static void	parse_eof(t_token **head, t_token **tail)
{
	t_token	*eof;

	eof = get_new_token(TK_EOF, NULL, 0);
	if (eof)
	{
		if (*tail)
			(*tail)->next = eof;
		else
			*head = eof;
		*tail = eof;
	}

}
