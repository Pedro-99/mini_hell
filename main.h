/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 04:34:17 by agaladi           #+#    #+#             */
/*   Updated: 2024/07/28 01:12:12 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>


typedef enum e_tokenType
{
	RED_IN,
	RED_OUT,
	APPEND,
	HERE_DOC,
	DELLIMITER,
	COMMAND,
	STRING,
	S_QUOTE,
	D_QUOTE,
	PIPE
}	e_tokenType;

typedef struct		s_token
{
	e_tokenType		type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct		s_opp
{
	e_tokenType		operator;
	char			*arg;
	struct s_opp	*next;
}					t_opp;

typedef struct		s_com
{
	char			**command;
	t_opp			*operator;
	struct s_com	*next;
}					t_com;


// utils
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *str);
void	add_lstback(t_opp *operators, t_opp *to_add);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *str1, char *str2);
t_token	*last_token(t_token *token);
// tokenizer
int		is_quote(char *str);
int		is_rederection(char *str);
char	*add_spaces(char *str);
void	switch_char(char **str, char to_find, char character);
char	*format(char *str);
char	*handle_quotes(char *str);
t_token	*tokenizer(char *input);
// lexer
void	trim_quotes(t_token **token);
int		check_pipes(t_token *token);
int		check_red(t_token *token);
int		is_red(e_tokenType type);
// errors
void	error(void);

#endif