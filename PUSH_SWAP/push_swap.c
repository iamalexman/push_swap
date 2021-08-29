/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:01:58 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:02:00 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_up_to_3(t_node **stack_a, t_spisok **commands, int size)
{
	size_t		flag;

	if (!(*stack_a))
		ft_error(0);
	flag = ft_is_sorted(*stack_a, size);
	while (flag == 0)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_sa(stack_a, *commands, 1);
		else if ((*stack_a)->data < (*stack_a)->next->data)
			ft_rra(stack_a, *commands, 1);
		flag = ft_is_sorted(*stack_a, size);
	}
}

void	ft_check_stack(t_node **stack)
{
	t_node	*tmp;
	int		data;

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

void	ft_sort_3_to_5_b(t_node **stack_a, t_node **stack_b, t_list *list,
						 t_spisok **commands)
{
	while (*stack_b)
	{
		if ((*stack_b)->data == list->mid)
		{
			ft_pa(stack_a, stack_b, *commands, list);
			if ((*stack_b)->data > (*stack_b)->next->data)
			{
				ft_pa(stack_a, stack_b, *commands, list);
				ft_pa(stack_a, stack_b, *commands, list);
			}
			else
			{
				ft_sb(stack_b, *commands, 1);
				ft_pa(stack_a, stack_b, *commands, list);
				ft_pa(stack_a, stack_b, *commands, list);
			}
		}
		else
			ft_rrb(stack_b, *commands, 1);
	}
}

void	sort_3_to_5(t_node **stack_a, t_node **stack_b, int size,
					t_spisok **commands)
{
	t_list		*list;
	int			*array;

	array = (int *)malloc((size) * sizeof(int));
	list = (t_list *)malloc ((size) * sizeof(t_list));
	ft_list_init(&list);
	ft_make_small_array(&array, stack_a);
	ft_array_sort(0, size - 1, &array);
	ft_get_index(stack_a, array);
	ft_get_list_param(array, &list, size);
	while (ft_is_sorted(*stack_a, list->size) < 1)
	{
		while (size-- > 0)
		{
			if ((*stack_a)->data <= list->mid)
				ft_pb(stack_a, stack_b, *commands, list);
			else
				ft_ra(stack_a, *commands, 1);
		}
		if ((*stack_a)->data == list->max && (*stack_a)->next)
			ft_ra(stack_a, *commands, 1);
		ft_sort_3_to_5_b (stack_a, stack_b, list, commands);
	}
	free(array);
	free(list);
}

int	main(int argc, char **argv)
{
	t_spisok	*commands;
	t_node		*stack_a;
	t_node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	commands = (t_spisok *)malloc(sizeof(t_spisok));
	ft_spisok_init(&commands);
	ft_push_stack(argc - 1, argv, &stack_a);
	if (ft_is_sorted(stack_a, argc - 1) == 1)
		exit(0);
	ft_check_stack(&stack_a);
	if (argc <= 4)
		sort_up_to_3 (&stack_a, &commands, argc - 1);
	else if (argc <= 6)
		sort_3_to_5 (&stack_a, &stack_b, argc - 1, &commands);
	else
		big_sort(&stack_a, &stack_b, argc - 1);
	ft_print_commands(commands);
	ft_free_commands_list(&commands);
	ft_free_stack(&stack_a);
	exit(0);
}
