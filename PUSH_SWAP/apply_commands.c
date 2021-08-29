/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:58:07 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:58:13 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_spisok	*ft_spisok_last(t_spisok *lst)
{
	if (!lst)
		ft_error(0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_spisok_add_back(t_spisok **spisok, t_spisok **new)
{
	t_spisok	*tmp;

	tmp = NULL;
	if (*spisok)
	{
		tmp = ft_spisok_last(*spisok);
		tmp->next = (*new);
	}
	else
		*spisok = (*new);
}

void	push_spisok(t_spisok **spisok, char *command)
{
	t_spisok	*new_list;

	new_list = ft_new_spisok(command);
	ft_spisok_add_back(spisok, &new_list);
}

int	pop(t_node **head)
{
	t_node	*tmp;
	int		data;

	if (*head == NULL)
		ft_error(0);
	tmp = *head;
	*head = (*head)->next;
	data = tmp->data;
	free(tmp);
	return (data);
}
