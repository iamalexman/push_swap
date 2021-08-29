/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:02:33 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:02:34 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **stack_a, t_spisok *spisok, size_t flag)
{
	t_spisok	*new_command;
	t_node		*tmp;

	if (*stack_a)
	{
		tmp = (*stack_a)->next;
		ft_lstlast(*stack_a)->next = *stack_a;
		(*stack_a)->next = NULL;
		*stack_a = tmp;
		if (flag == 1)
		{
			new_command = ft_new_spisok("ra\n");
			ft_spisok_add_back(&spisok, &new_command);
		}
	}
}

void	ft_rb(t_node **stack_b, t_spisok *spisok, size_t flag)
{
	t_spisok	*new_command;
	t_node		*tmp;

	if (*stack_b)
	{
		tmp = (*stack_b)->next;
		ft_lstlast(*stack_b)->next = *stack_b;
		(*stack_b)->next = NULL;
		*stack_b = tmp;
		if (flag == 1)
		{
			new_command = ft_new_spisok("rb\n");
			ft_spisok_add_back(&spisok, &new_command);
		}
	}
}

void	ft_rr(t_node **stack_a, t_node **stack_b, t_spisok *spisok)
{
	t_spisok	*new_command;

	if (*stack_a)
		ft_sa(stack_a, spisok, 0);
	if (*stack_b)
		ft_sb(stack_b, spisok, 0);
	new_command = ft_new_spisok("rr\n");
	ft_spisok_add_back(&spisok, &new_command);
}

void	ft_rra(t_node **stack_a, t_spisok *spisok, size_t flag)
{
	t_spisok	*new_command;
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
		if (flag == 1)
		{
			new_command = ft_new_spisok("rra\n");
			ft_spisok_add_back(&spisok, &new_command);
		}
	}
}

void	ft_rrb(t_node **stack_b, t_spisok *spisok, size_t flag)
{
	t_spisok	*new_command;
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
		if (flag == 1)
		{
			new_command = ft_new_spisok("rrb\n");
			ft_spisok_add_back(&spisok, &new_command);
		}
	}
}
