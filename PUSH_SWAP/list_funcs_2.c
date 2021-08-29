/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:00:19 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:00:21 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_spisok	*ft_spisok_last(t_spisok *lst)
{
	if (!lst)
		ft_error(0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_spisok	*ft_new_spisok(char *command)
{
	t_spisok	*spisok;

	spisok = (t_spisok *)malloc(sizeof(t_spisok));
	if (!spisok)
		ft_error(0);
	ft_spisok_init(&spisok);
	if (!spisok)
		return (NULL);
	spisok->command = command;
	return (spisok);
}

void	ft_spisok_init(t_spisok **spisok)
{
	(*spisok)->command = "\0";
	(*spisok)->next = NULL;
}

void	push_spisok(t_spisok **spisok, char *command)
{
	t_spisok	*new_list;

	new_list = ft_new_spisok(command);
	ft_spisok_add_back(spisok, &new_list);
}
