/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:41:13 by dong-hki          #+#    #+#             */
/*   Updated: 2025/02/14 11:54:04 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define SINGLE_QUOTE '\''
# define DOUBLE_QUOTE '\"'

typedef enum e_state
{
	STATE_NORMAL,
	STATE_SINGLE_QUOTE,
	STATE_DOUBLE_QUOTE
}	t_state;

typedef struct s_token
{
	char	**token;
	int		token_size;
}	t_token;

size_t	get_buflen(char **str);
t_state	init_state(char **argv);
int		token_count(char *argv);
char	**tokenizer(const char *argv, int token_count);

#endif
