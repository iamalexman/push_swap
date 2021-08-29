/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:01:23 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:01:25 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_node **stack)
{
	t_node		*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
	tmp = NULL;
}

void	ft_sb(t_node **stack)
{
	t_node		*tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		*stack = tmp;
		tmp = NULL;
	}
	else
		return ;
}

void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
		ft_sa(stack_a);
	else
		return ;
	if (*stack_b)
		ft_sb(stack_b);
	else
		return ;
}

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	t_node		*new;
	int			data;

	data = pop(stack_b);
	new = ft_lstnew(data);
	add_front(stack_a, new);
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node		*new;
	int			data;

	data = pop(stack_a);
	new = ft_lstnew(data);
	add_front(stack_b, new);
}
