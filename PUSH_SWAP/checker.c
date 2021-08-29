/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:59:36 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:59:38 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_apply_commands(t_node **stack_a, t_node **stack_b,
							   t_spisok **list)
{
	if (ft_strcmp ((*list)->command, "sa\n") == 0)
		return (ft_sa(stack_a));
	else if (ft_strcmp((*list)->command, "sb\n") == 0)
		return (ft_sb(stack_b));
	else if (ft_strcmp((*list)->command, "ss\n") == 0)
		return (ft_ss(stack_a, stack_b));
	else if (ft_strcmp((*list)->command, "pa\n") == 0)
		return (ft_pa(stack_a, stack_b));
	else if (ft_strcmp((*list)->command, "pb\n") == 0)
		return (ft_pb(stack_a, stack_b));
	else if (ft_strcmp((*list)->command, "ra\n") == 0)
		return (ft_ra(stack_a));
	else if (ft_strcmp((*list)->command, "rb\n") == 0)
		return (ft_rb(stack_b));
	else if (ft_strcmp((*list)->command, "rr\n") == 0)
		return (ft_rr(stack_a, stack_b));
	else if (ft_strcmp((*list)->command, "rra\n") == 0)
		return (ft_rra(stack_a));
	else if (ft_strcmp((*list)->command, "rrb\n") == 0)
		return (ft_rrb(stack_b));
	else if (ft_strcmp((*list)->command, "rrr\n") == 0)
		return (ft_rrr(stack_a, stack_b));
}

int	ft_check_commands(t_spisok *list, t_list **commands)
{
	int	size;

	size = (*commands)->size;
	if (ft_strcmp(list->command, "sa\n") == 0
		|| ft_strcmp(list->command, "sb\n") == 0
		|| ft_strcmp(list->command, "ss\n") == 0
		|| ft_strcmp(list->command, "pa\n") == 0
		|| ft_strcmp(list->command, "pb\n") == 0
		|| ft_strcmp(list->command, "ra\n") == 0
		|| ft_strcmp(list->command, "rb\n") == 0
		|| ft_strcmp(list->command, "rr\n") == 0
		|| ft_strcmp(list->command, "rra\n") == 0
		|| ft_strcmp(list->command, "rrb\n") == 0
		|| ft_strcmp(list->command, "rrr\n") == 0
		|| list->command == NULL)
		return (0);
	else
		return (1);
}

static void	ft_get_commands(t_spisok **list)
{
	char	*command;
	int		out;
	int		fd;
	int		i;

	i = 0;
	fd = 0;
	out = 1;
	command = NULL;
	while (out == 1)
	{
		out = get_next_line(fd, &command);
		if (i == 0)
			(*list)->command = command;
		else
			push_spisok(&(*list), command);
		i++;
	}
	free(command);
}

static void	ft_check_magic(t_node **stack_a, t_node **stack_b, t_spisok **list,
		t_list **values)
{
	t_spisok	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (ft_check_commands(*list, values) == 1 )
			ft_error(0);
		tmp = tmp->next;
	}
	tmp = *list;
	while (tmp)
	{
		ft_apply_commands(stack_a, stack_b, &tmp);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_spisok	*list;
	t_node		*stack_a;
	t_node		*stack_b;
	t_list		*values;

	stack_a = NULL;
	stack_b = NULL;
	values = (t_list *)malloc(sizeof(t_list));
	list = (t_spisok *)malloc(sizeof(t_spisok));
	ft_list_init(&values);
	values->size = argc - 1;
	if (!list)
		ft_error(0);
	ft_spisok_init(&list);
	ft_push_checker_stack(argc - 1, argv, &stack_a);
	ft_check_stack(&stack_a);
	ft_get_commands(&list);
	ft_check_magic(&stack_a, &stack_b, &list, &values);
	ft_sort_status(&stack_a, &stack_b, list, &values);
	free(values);
	exit (0);
}
