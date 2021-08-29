/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:59:43 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 11:59:46 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# ifndef FD_BUFFER
#  define FD_BUFFER 1024
# endif

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node {
	int				index;
	int				data;
	int				flag;
	struct s_node	*next;
}		t_node;

typedef struct s_spisok {
	char			*command;
	struct s_spisok	*next;
}		t_spisok;

typedef struct s_list {
	int		flag;
	int		min;
	int		mid;
	int		max;
	int		size;
	int		iter;
}		t_list;

int			ft_strlen(char *s);
int			ft_strcmp(char *str1, char *str2);
int			get_next_line(int fd, char **line);
long		ft_checker_atoi(char *str);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);

void		ft_list_init(t_list **list);
void		ft_error(void *data);
void		ft_spisok_init(t_spisok **spisok);
int			ft_is_sorted(t_node *stack, int size);

void		ft_sa(t_node **stack);
void		ft_sb(t_node **stack);
void		ft_ss(t_node **stack_a, t_node **stack_b);
void		ft_pb(t_node **stack_a, t_node **stack_b);
void		ft_pa(t_node **stack_a, t_node **stack_b);
void		ft_ra(t_node **stack_a);
void		ft_rb(t_node **stack_b);
void		ft_rr(t_node **stack_a, t_node **stack_b);
void		ft_rra(t_node **stack_a);
void		ft_rrb(t_node **stack_b);
void		ft_rrr(t_node **stack_a, t_node **stack_b);
int			pop(t_node **head);
int			ft_check_commands(t_spisok *list, t_list **commands);
void		push(t_node **stack_a, int data);
void		push_spisok(t_spisok **spisok, char *command);
void		ft_spisok_add_back(t_spisok **spisok, t_spisok **new);
void		add_front(t_node **lst, t_node *new);
void		ft_stack_init(t_node **stack);
void		ft_lstadd_back(t_node **stack, t_node **new);
void		ft_check_stack(t_node **stack);
void		ft_push_checker_stack(int argc, char **argv, t_node **stack_a);
void		ft_sort_status(t_node **stack_a, t_node **stack_b, t_spisok *list,
				t_list **values);
t_node		*ft_lstnew(int data);
t_node		*ft_lstlast(t_node *lst);
t_node		*ft_prev(t_node *lst);
t_spisok	*ft_new_spisok(char *command);
t_spisok	*ft_spisok_last(t_spisok *lst);

#endif
