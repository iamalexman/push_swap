/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_support_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:01:46 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:01:47 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_node **stack_a, t_node **stack_b, t_spisok *spisok,
			   size_t flag)
{
	t_spisok	*new_command;
	size_t		i;

	i = flag;
	i = 0;
	if (*stack_a && (*stack_a)->next)
		ft_rra(stack_a, spisok, i);
	if (*stack_b && (*stack_b)->next)
		ft_rrb(stack_b, spisok, i);
	new_command = ft_new_spisok("rrr\n");
	ft_spisok_add_back(&spisok, &new_command);
}

void	ft_lstadd_back(t_node **stack, t_node **new)
{
	t_node	*tmp;

	tmp = NULL;
	if (*stack)
	{
		tmp = ft_lstlast(*stack);
		tmp->next = (*new);
	}
	else
		*stack = (*new);
}

void	ft_spisok_init(t_spisok **spisok)
{
	(*spisok)->command = "\0";
	(*spisok)->next = NULL;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str1[i] == '\0' && i == 0)
		return (1);
	return (0);
}
