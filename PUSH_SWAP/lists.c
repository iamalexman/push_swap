/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:00:30 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:00:31 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		ft_error(0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node	*ft_prev(t_node *lst)
{
	if (!lst)
		ft_error(0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_stack_init(t_node **stack)
{
	(*stack)->index = 0;
	(*stack)->data = 0;
	(*stack)->flag = 0;
	(*stack)->next = NULL;
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

void	add_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
