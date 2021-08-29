/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:01:02 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:01:04 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	push(t_node **stack_a, int data)
{
	t_node	*new_list;

	new_list = ft_lstnew(data);
	ft_lstadd_back(stack_a, &new_list);
}

int	ft_is_sorted(t_node *stack, int size)
{
	int	i;

	i = 1;
	while (stack->next)
	{
		i++;
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	if (size != i)
		return (0);
	return (1);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		ft_error(0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_node **stack, t_node **new)
{
	t_node	*tmp;

	tmp = NULL;
	if (*stack)
	{
		tmp = ft_lstlast(*stack);
		tmp->next = (*new);
	}
	else
		*stack = (*new);
}
