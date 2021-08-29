/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:58:58 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:59:00 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b(t_list **list, t_spisok **spisok, t_node **stack_a,
				  t_node **stack_b)
{
	int		*array;

	(*list)->size = stack_size_b(*stack_b, *list);
	array = (int *)malloc((*list)->size * sizeof(int));
	ft_make_array(&array, stack_b);
	ft_array_sort(0, (*list)->size - 1, &array);
	(*list)->min = array[0];
	(*list)->max = array[(*list)->size - 1];
	if ((*list)->flag != 0)
		(*list)->max = (*list)->mid;
	(*list)->mid = (((*list)->max - (*list)->min) / 2) + (*list)->min;
	(*list)->flag++;
	while ((*list)->size--)
	{
		if ((*stack_b)->data >= (*list)->mid || (*stack_b)->data
			== (*list)->min)
		{
			ft_pa(stack_a, stack_b, *spisok, *list);
			if ((*stack_a)->data == (*list)->min)
				ft_go_down (*list, *spisok, stack_a);
		}
		else
			ft_rb(stack_b, *spisok, 1);
	}
	free (array);
}

void	ft_sort_b_2(t_list **list, t_spisok **spisok, t_node **stack_a,
					t_node **stack_b)
{
	int		*array;
	int		size;
	int		max;
	int		mid;

	size = stack_size_b(*stack_b, *list);
	array = (int *)malloc(size * sizeof(int));
	ft_make_array(&array, stack_b);
	ft_array_sort(0, size - 1, &array);
	max = array[size - 1];
	mid = array[(max - array[0]) / 2];
	(*list)->flag++;
	while (size--)
	{
		if ((*stack_b)->data >= mid || (*stack_b)->data == (*list)->min)
		{
			ft_pa(stack_a, stack_b, *spisok, *list);
			if ((*stack_a)->data == (*list)->min)
				ft_go_down (*list, *spisok, stack_a);
		}
		else
			ft_rb(stack_b, *spisok, 1);
	}
	free (array);
}

void	ft_sort_a_2(t_list **list, t_spisok **spisok, t_node **stack_a,
					t_node **stack_b)
{
	int		*array;

	(*list)->size = stack_size(*stack_a, *list);
	array = (int *)malloc((*list)->size * sizeof(int));
	ft_make_array_2(&array, stack_a);
	ft_array_sort(0, (*list)->size - 1, &array);
	(*list)->min = array[0];
	(*list)->max = array[(*list)->size - 1];
	(*list)->mid = array[(*list)->size / 2];
	while ((*stack_a)->flag > 0 && !(*stack_b))
	{
		ft_check_peek(list, spisok, stack_a);
		while ((*stack_a)->flag == (*list)->flag)
			if ((*stack_a)->data == (*list)->min)
				ft_go_down(*list, *spisok, stack_a);
		else
			ft_pb(stack_a, stack_b, *spisok, *list);
		while (*stack_b)
			ft_sort_b_2(list, spisok, stack_a, stack_b);
		(*list)->flag = (*stack_a)->flag;
	}
	if ((*stack_a)->flag == 0)
		(*list)->iter = 0;
	free (array);
}

void	ft_sort_a(t_list **list, t_spisok **spisok, t_node **stack_a,
				  t_node **stack_b)
{
	int		*array;

	(*list)->size = stack_size(*stack_a, *list);
	array = (int *)malloc((*list)->size * sizeof(int));
	ft_make_array(&array, stack_a);
	ft_array_sort(0, (*list)->size - 1, &array);
	if ((*list)->iter == 0 && !(*spisok)->next)
		ft_get_index(stack_a, array);
	(*list)->min = array[0];
	(*list)->max = array[(*list)->size - 1];
	(*list)->mid = array[(*list)->size / 2];
	(*list)->iter++;
	while ((*list)->size--)
	{
		if ((*stack_a)->data >= (*list)->mid)
		{
			ft_ra(stack_a, *spisok, 1);
			(*list)->iter++;
		}
		else
			ft_pb(stack_a, stack_b, *spisok, *list);
	}
	if ((*stack_a)->flag < 0 && *stack_b)
		ft_stack_reverse(*list, *spisok, stack_a, stack_b);
	free(array);
}

void	big_sort(t_node **stack_a, t_node **stack_b, int size)
{
	t_spisok	*spisok;
	t_list		*list;

	list = (t_list *)malloc(sizeof(t_list));
	spisok = (t_spisok *)malloc(sizeof(t_spisok));
	if (!spisok || !list)
		ft_error(0);
	ft_list_init (&list);
	ft_spisok_init (&spisok);
	while (ft_is_sorted(*stack_a, size) < 1)
	{
		ft_check_peek(&list, &spisok, stack_a);
		if (list->iter == 0)
			ft_sort_a(&list, &spisok, stack_a, stack_b);
		else
			ft_sort_a_2(&list, &spisok, stack_a, stack_b);
		while (*stack_b)
			ft_sort_b(&list, &spisok, stack_a, stack_b);
	}
	ft_print_commands(spisok);
	ft_free_commands_list(&spisok);
	free (list);
}
