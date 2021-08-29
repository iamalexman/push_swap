/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:00:52 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:00:54 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_make_small_array(int **array, t_node **stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (!array)
		ft_error(0);
	tmp = *stack;
	while (tmp)
	{
		(*array)[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

void	ft_check_stack(t_node **stack)
{
	t_node	*tmp;
	int		data;

	if (!*stack)
		exit(0);
	tmp = *stack;
	while (*stack)
	{
		data = (*stack)->data;
		while (tmp->next)
		{
			if (data == tmp->next->data)
				ft_error(0);
			tmp = tmp->next;
		}
		stack = &(*stack)->next;
		tmp = *stack;
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

int	ft_array_separation(int start, int end, int **arr)
{
	int	mid;
	int	tmp;
	int	i;
	int	j;

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
