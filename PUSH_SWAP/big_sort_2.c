/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:59:08 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:59:09 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_commands(t_spisok *spisok)
{
	while (spisok)
	{
		if (ft_strlen(spisok->command) == 4)
			write(1, spisok->command, 4);
		else if (ft_strlen(spisok->command) == 3)
			write(1, spisok->command, 3);
		spisok = spisok->next;
	}
}

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free (tmp);
	}
	tmp = NULL;
	free (*stack);
}

void	ft_stack_reverse(t_list *list, t_spisok *spisok, t_node **stack_a,
						 t_node **stack_b)
{
	while ((*stack_b) && list->iter > 1)
	{
		if ((*stack_b)->data == list->min)
			ft_rra(stack_a, spisok, 1);
		else
			ft_rrr(stack_a, stack_b, spisok, 1);
		list->iter--;
	}
}

int	ft_check_peek(t_list **list, t_spisok **spisok, t_node **stack)
{
	int	i;

	i = 0;
	if ((*stack)->data == (*list)->min)
	{
		(*stack)->flag = -1;
		(*list)->min++;
		ft_ra(stack, *spisok, 1);
		ft_check_peek(list, spisok, stack);
		i += 1;
	}
	else if ((*stack)->next->data == (*list)->min)
	{
		ft_sa(stack, *spisok, 1);
		(*stack)->flag = -1;
		ft_ra(stack, *spisok, 1);
		(*list)->min++;
		ft_check_peek(list, spisok, stack);
		i += 1;
	}
	return (i);
}

int	ft_check_peek_b(t_list *list, t_spisok **spisok, t_node **stack_a,
					t_node **stack_b)
{
	if ((*stack_b) && (*stack_b)->data == list->min)
	{
		if ((*stack_b)->data == list->min)
		{
			(*stack_b)->flag = -1;
			list->min++;
			list->size--;
			ft_pa(stack_a, stack_b, *spisok, list);
			ft_ra(stack_a, *spisok, 1);
			if ((*stack_b) != NULL)
				ft_check_peek_b(list, spisok, stack_a, stack_b);
		}
		if (list->size == 1)
			return (-1);
	}
	return (0);
}
