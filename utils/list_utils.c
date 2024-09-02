/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzinedda <bzinedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:39:53 by agaladi           #+#    #+#             */
/*   Updated: 2024/08/02 03:21:00 by bzinedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_lstback(t_opp *operators, t_opp *to_add)
{
	t_opp *current;

	current = operators;
	if (!operators)
		operators = to_add;
	else
	{
		while (current->next)
			current = current->next;
		current->next = to_add;
	}
}

t_token	*last_token(t_token *token)
{
	t_token	*current;

	current = token;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}
