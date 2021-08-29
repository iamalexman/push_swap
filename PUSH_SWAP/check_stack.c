/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:59:19 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:59:21 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_list_param(int *array, t_list **list, int size)
{
	(*list)->min = array[0];
	(*list)->max = array[size - 1];
	(*list)->mid = array[2];
	(*list)->size = size;
}

void	ft_free_commands_list(t_spisok **commands)
{
	t_spisok	*tmp;

	tmp = *commands;
	while ((*commands)->next)
	{
		tmp = *commands;
		*commands = (*commands)->next;
		free (tmp);
	}
	free (*commands);
}

void	ft_error(void *data)
{
	int		*i;

	i = NULL;
	i = data;
	exit((int)write(1, "Error\n", 6));
}

void	ft_push_stack(int argc, char **argv, t_node **stack_a)
{
	long	data;
	size_t	i;

	i = 1;
	while (argc--)
	{
		data = ft_atoi(argv[i]);
		if (data > INT_MAX || data < INT_MIN)
			ft_error(0);
		push(stack_a, (int)data);
		i++;
	}
}

int	ft_is_sorted(t_node *stack, int size)
{
	int	i;

	i = 1;
	if (!stack)
		ft_error(0);
	while (stack->next)
	{
		i++;
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	if (size != i)
		return (0);
	return (1);
}
