/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_checker_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:02:57 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:02:59 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sort_status(t_node **stack_a, t_node **stack_b, t_spisok *list,
						t_list **values)
{
	int	status;

	status = ft_check_commands(list, values);
	if (ft_is_sorted(*stack_a, (*values)->size) && !*stack_b && status == 0)
		write (1, "OK\n", 3);
	else if (!ft_is_sorted(*stack_a, (*values)->size) || *stack_b)
		write (1, "KO\n", 3);
	else if (status == 0 && !(*stack_a)->next && !(*stack_b)->next)
		exit(0);
	else
		ft_error(0);
}

void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		ft_rra(stack_a);
	if (*stack_b && (*stack_b)->next)
		ft_rrb(stack_b);
}

long	ft_checker_atoi(char *str)
{
	size_t	sign;
	long	res;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
		ft_error(0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i] - '0'));
		i++;
	}
	if (i > 11)
		ft_error(0);
	return (res * sign);
}

void	ft_push_checker_stack(int argc, char **argv, t_node **stack_a)
{
	long	data;
	size_t	i;

	i = 1;
	while (argc--)
	{
		data = ft_checker_atoi(argv[i]);
		if (data > INT_MAX || data < INT_MIN)
			ft_error(0);
		push(stack_a, (int)data);
		i++;
	}
}

void	ft_error(void *data)
{
	int	*i;

	i = data;
	exit((int)write(1, "Error\n", 6));
}
