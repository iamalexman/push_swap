/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:00:11 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:00:13 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

t_node	*ft_prev(t_node *lst)
{
	if (!lst)
		ft_error(0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

t_node	*ft_lstnew(int data)
{
	t_node	*stack;

	stack = (t_node *)malloc(sizeof(t_node));
	if (!stack)
		ft_error(0);
	ft_stack_init(&stack);
	if (!stack)
		return (NULL);
	stack->data = data;
	return (stack);
}

void	ft_stack_init(t_node **stack)
{
	(*stack)->index = 0;
	(*stack)->data = 0;
	(*stack)->flag = 0;
	(*stack)->next = NULL;
}

void	ft_list_init(t_list **list)
{
	if (!list)
		ft_error(0);
	(*list)->flag = 0;
	(*list)->max = 0;
	(*list)->mid = 0;
	(*list)->min = 0;
	(*list)->size = 0;
	(*list)->iter = 0;
}
