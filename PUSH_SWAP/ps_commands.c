/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:01:32 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:01:34 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_node **stack_a)
{
	t_node		*tmp;

	if (*stack_a)
	{
		tmp = (*stack_a)->next;
		ft_lstlast(*stack_a)->next = *stack_a;
		(*stack_a)->next = NULL;
		*stack_a = tmp;
	}
	else
		return ;
}

void	ft_rb(t_node **stack_b)
{
	t_node		*tmp;

	if (*stack_b)
	{
		tmp = (*stack_b)->next;
		ft_lstlast(*stack_b)->next = *stack_b;
		(*stack_b)->next = NULL;
		*stack_b = tmp;
	}
	else
		return ;
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
		ft_sa(stack_a);
	if (*stack_b)
		ft_sb(stack_b);
}

void	ft_rra(t_node **stack_a)
{
	t_node		*last;
	t_node		*head;
	t_node		*prev;

	if (*stack_a)
	{
		head = *stack_a;
		last = ft_lstlast(*stack_a);
		prev = ft_prev(*stack_a);
		prev->next = NULL;
		last->next = head;
		*stack_a = last;
	}
	else
		return ;
}

void	ft_rrb(t_node **stack_b)
{
	t_node		*last;
	t_node		*head;
	t_node		*prev;

	if (*stack_b)
	{
		head = *stack_b;
		last = ft_lstlast(*stack_b);
		prev = ft_prev(*stack_b);
		prev->next = NULL;
		last->next = head;
		*stack_b = last;
	}
	else
		return ;
}
