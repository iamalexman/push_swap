/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:58:28 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:58:30 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_array_separation(int start, int end, int **arr)
{
	int		mid;
	int		tmp;
	int		i;
	int		j;

	mid = (*arr)[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if ((*arr)[j] <= mid)
		{
			i++;
			tmp = (*arr)[i];
			(*arr)[i] = (*arr)[j];
			(*arr)[j] = tmp;
		}
		j++;
	}
	tmp = (*arr)[i + 1];
	(*arr)[i + 1] = (*arr)[end];
	(*arr)[end] = tmp;
	return (i + 1);
}

void	ft_array_sort(int start, int end, int **arr)
{
	int	s;

	if (start < end)
	{
		s = ft_array_separation(start, end, arr);
		ft_array_sort(start, s - 1, arr);
		ft_array_sort(s + 1, end, arr);
	}
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

void	ft_simple_sort_b(t_list *list, t_spisok *spisok, t_node **stack_a,
						 t_node **stack_b)
{
	while (*stack_b)
	{
		if ((*stack_b)->data == list->min)
		{
			ft_pa(stack_a, stack_b, spisok, list);
			ft_go_down (list, spisok, stack_a);
		}
		else
		{
			ft_sb(stack_b, spisok, 0);
			ft_simple_sort_b(list, spisok, stack_a, stack_b);
		}
	}
}
