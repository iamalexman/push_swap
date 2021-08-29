/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:02:20 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:02:22 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **stack, t_spisok *spisok, size_t flag)
{
	t_spisok	*new_command;
	t_node		*tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		*stack = tmp;
		tmp = NULL;
		if (flag == 1)
		{
			new_command = ft_new_spisok("sa\n");
			ft_spisok_add_back(&spisok, &new_command);
		}
	}
}

void	ft_sb(t_node **stack, t_spisok *spisok, size_t flag)
{
	t_spisok	*new_command;
	t_node		*tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		*stack = tmp;
		tmp = NULL;
		if (flag == 1)
		{
			new_command = ft_new_spisok("sb\n");
			ft_spisok_add_back(&spisok, &new_command);
		}
	}
}

void	ft_ss(t_node **stack_a, t_node **stack_b, t_spisok *spisok)
{
	t_spisok	*new_command;

	if (*stack_a)
		ft_sa(stack_a, spisok, 0);
	if (*stack_b)
		ft_sb(stack_b, spisok, 0);
	new_command = ft_new_spisok("ss\n");
	ft_spisok_add_back(&spisok, &new_command);
}

void	ft_pa(t_node **stack_a, t_node **stack_b, t_spisok *spisok,
			  t_list *list)
{
	t_spisok	*new_command;
	t_node		*new;
	int			index;
	int			data;
	int			flag;

	flag = list->flag;
	index = (*stack_b)->index;
	data = pop(stack_b);
	new = ft_lstnew(data);
	add_front(stack_a, new);
	new_command = ft_new_spisok("pa\n");
	ft_spisok_add_back(&spisok, &new_command);
	(*stack_a)->flag = flag;
	(*stack_a)->index = index;
}

void	ft_pb(t_node **stack_a, t_node **stack_b, t_spisok *spisok,
			  t_list *list)
{
	t_spisok	*new_command;
	t_node		*new;
	int			index;
	int			data;
	int			flag;

	flag = list->flag;
	index = (*stack_a)->index;
	data = pop(stack_a);
	new = ft_lstnew(data);
	add_front(stack_b, new);
	new_command = ft_new_spisok("pb\n");
	ft_spisok_add_back(&spisok, &new_command);
	(*stack_b)->flag = flag;
	(*stack_b)->index = index;
}
