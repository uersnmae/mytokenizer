/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:41:13 by dong-hki          #+#    #+#             */
/*   Updated: 2025/04/21 03:08:45 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <stdio.h>
# include <stdlib.h>

typedef enum e_state
{
	STATE_NORMAL,
	STATE_SINGLE_QUOTE,
	STATE_DOUBLE_QUOTE
}	t_state;

typedef enum e_toktype
{
	TK_WORD,
	TK_PIPE,
	TK_REDIR_IN,
	TK_REDIR_OUT,
	TK_D_REDIR_IN,
	TK_D_REDIR_OUT,
	TK_LPAR,
	TK_RPAR,
	TK_AND_IF,
	TK_OR_IF,
	TK_EOF
}	t_toktype;

typedef struct s_token
{
	t_toktype		type;
	int				token_size;
	char			*value;
	struct s_token	*next;
}	t_token;

int			is_operator_start(char c);
t_token		*get_new_token(t_toktype type, const char *start, size_t len);
t_toktype	get_operator(const char **str);
void		free_tokens(t_token *head);

t_token		*tokenize(const char *input);

#endif
