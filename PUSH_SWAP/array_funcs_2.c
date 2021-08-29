/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_funcs_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:58:41 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:58:43 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_array(int **array, t_node **stack)
{
	t_node	*tmp;
	int		flag;
	int		i;

	i = 0;
	if (!array)
		ft_error(0);
	tmp = *stack;
	flag = tmp->flag;
	while (tmp && tmp->flag == flag)
	{
		(*array)[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

void	ft_make_small_array(int **array, t_node **stack)
{
	t_node	*tmp;
	int		flag;
	int		i;

	i = 0;
	if (!array)
		ft_error(0);
	tmp = *stack;
	flag = tmp->flag;
	while (tmp)
	{
		(*array)[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

void	ft_make_array_2(int **array, t_node **stack)
{
	t_node	*tmp;
	int		flag;
	int		i;

	i = 0;
	if (!array)
		ft_error(0);
	tmp = *stack;
	flag = tmp->flag;
	while (tmp && tmp->flag > 0)
	{
		(*array)[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

void	ft_get_index(t_node **stack, int *array)
{
	t_node	*tmp;
	int		i;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (array[i] != tmp->data)
			i++;
		tmp->index = i + 1;
		tmp = tmp->next;
	}
}

void	ft_go_down(t_list *list, t_spisok *spisok, t_node **stack_a)
{
	list->min += 1;
	(*stack_a)->flag = -1;
	ft_ra(stack_a, spisok, 1);
	ft_check_peek(&list, &spisok, stack_a);
}
