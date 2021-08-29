/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:02:46 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:02:47 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_a, int data)
{
	t_node	*new_list;

	new_list = ft_lstnew(data);
	ft_lstadd_back(stack_a, &new_list);
}

int	stack_size(t_node *stack, t_list *list)
{
	t_node	*tmp;
	int		size;

	size = 0;
	tmp = stack;
	if (list->iter == 0)
	{
		while (tmp && tmp->flag >= 0)
		{
			tmp = tmp->next;
			size++;
		}
	}
	else
	{
		while (tmp && tmp->flag > 0 && (tmp)->flag != -1)
		{
			tmp = tmp->next;
			size++;
		}
	}
	return (size);
}

int	stack_size_b(t_node *stack, t_list *list)
{
	t_node	*tmp;
	int		size;

	size = list->iter;
	size = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

long	ft_atoi(char *str)
{
	size_t	sign;
	long	res;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
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
	return (res * sign);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s = (char *) malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
