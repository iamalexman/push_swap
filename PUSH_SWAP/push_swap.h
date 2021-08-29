/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:02:04 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:02:08 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_spisok {
	char			*command;
	struct s_spisok	*next;
}				t_spisok;

typedef struct s_node {
	int				index;
	int				data;
	int				flag;
	struct s_node	*next;
}				t_node;

typedef struct s_list {
	int		flag;
	int		min;
	int		mid;
	int		max;
	int		size;
	int		iter;
}				t_list;

char		*ft_strdup(char *s1);
int			ft_strcmp(char *str1, char *str2);

t_spisok	*ft_new_spisok(char *command);
t_node		*ft_lstlast(t_node *lst);
t_node		*ft_prev(t_node *lst);
t_node		*ft_lstnew(int data);
void		ft_lstadd_back(t_node **lst, t_node **new);
void		ft_free_lists(t_node **stack_a);
void		ft_stack_init(t_node **stack);
void		ft_spisok_init(t_spisok **spisok);
void		ft_spisok_add_back(t_spisok **spisok, t_spisok **new);
void		ft_print_commands(t_spisok *spisok);
void		ft_free_commands_list(t_spisok **commands);
void		ft_free_stack(t_node **stack);
void		push_spisok(t_spisok **spisok, char *command);

void		push(t_node **stack_a, int data);
int			pop(t_node **head);
void		add_front(t_node **stack, t_node *new);
void		ft_go_down(t_list *list, t_spisok *spisok, t_node **stack_a);

void		ft_sa(t_node **stack, t_spisok *spisok, size_t flag);
void		ft_sb(t_node **stack, t_spisok *spisok, size_t flag);
void		ft_ss(t_node **stack_a, t_node **stack_b, t_spisok *spisok);
void		ft_pa(t_node **stack_a, t_node **stack_b, t_spisok *spisok,
				t_list *list);
void		ft_pb(t_node **stack_a, t_node **stack_b, t_spisok *spisok,
				t_list *list);
void		ft_ra(t_node **stack_a, t_spisok *spisok, size_t flag);
void		ft_rb(t_node **stack_b, t_spisok *spisok, size_t flag);
void		ft_rr(t_node **stack_a, t_node **stack_b, t_spisok *spisok);
void		ft_rra(t_node **stack_a, t_spisok *spisok, size_t flag);
void		ft_rrb(t_node **stack_b, t_spisok *spisok, size_t flag);
void		ft_rrr(t_node **stack_a, t_node **stack_b, t_spisok *spisok,
				size_t flag);

void		sort_up_to_3(t_node **stack_a, t_spisok **spisok, int size);
void		sort_3_to_5(t_node **stack_a, t_node **stack_b, int size,
				t_spisok **spisok);
void		sort_3_to_5_b(t_node **stack_a, t_node **stack_b, int size,
				t_spisok **commands);
void		big_sort(t_node **stack_a, t_node **stack_b, int size);
void		ft_check_stack(t_node **stack);
void		ft_push_stack(int argc, char **argv, t_node **stack_a);
int			ft_check_peek(t_list **list, t_spisok **spisok, t_node **stack);
int			ft_is_sorted(t_node *stack, int size);
int			stack_size(t_node *stack, t_list *list);
int			stack_size_2(t_node *stack, t_list *list);
int			stack_size_b(t_node *stack, t_list *list);
void		ft_stack_reverse(t_list *list, t_spisok *spisok, t_node **stack_a,
				t_node **stack_b);
int			ft_strlen(char *s);
void		ft_error(void *data);
long		ft_atoi(char *str);
void		ft_list_init(t_list **list);
void		ft_make_array(int **array, t_node **stack);
void		ft_make_array_2(int **array, t_node **stack);
void		ft_make_small_array(int **array, t_node **stack);
void		ft_array_sort(int start, int end, int **arr);
void		ft_get_index(t_node **stack, int *array);
void		ft_get_list_param(int *array, t_list **list, int size);

#endif
