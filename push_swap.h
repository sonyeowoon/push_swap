/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:18:17 by sangseo           #+#    #+#             */
/*   Updated: 2024/11/17 23:26:23 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_node
{
	int				n;
	struct s_node	*next;
}	t_node;

typedef struct s_stackinfo
{
	int	a_size;
	int	b_size;
	t_node	*a;
	t_node	*b;
}	t_stackinfo;
// typedef struct s_stack
// {
// 	int		size;
// 	t_node	*front;
// 	t_node	*back;
// }	t_stack;

t_node	*ft_lstnew(int n);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
t_node	*make_stack(char **av);
int		chk_dupnsort(t_node *a);
void	ft_error(t_node *a);
void	ft_swap(char *cmd, t_node **lst);
void	ft_push(char *cmd, t_node **give, t_node **take);
void	ft_rotate(char *cmd, t_node **lst);
void	ft_reverse_rotate(char *cmd, t_node **lst);
void	double_cmd(char *cmd, t_node **a, t_node **b);
void	stack_free(t_node *lst);

void	ft_sorting(t_node *a, t_node *b);
int		chk_ascending(t_node *lst);
int		get_min(t_node *lst);
int		get_max(t_node *lst);
int		find_median(t_node *lst, int flg, int min, int max);
void	find_pivot(t_node **a, int pivot[4]);
//void	get_topbot(t_node *b, int i, int pivot[4], int *top, int *bot);
void	divide_pivot(t_node **a, t_node**b, int pivot[4]);
int		find_min_node(t_node *lst);
void	min_to_top(t_node **lst, int size);
int		get_paidx(t_node *a, t_node *b, int a_size, int b_size);
int		get_aidx(t_node *a, int bn);
void	pa_min(t_node **a, t_node **b, int min_idx);
void	pa_flg(t_node **a, t_node **b, int min_idx, int flg);
int		get_bn(t_node *b, int idx);

//void	min_to_top(t_node **lst, int size, int *max_idx, int *max_top);
// int		find_max_node(t_node *lst);
// int		find_nextmax_node(t_node *a, int max_idx, int max_top);
// void	over_idx_handling(int *idx, int size);
// void	next_max_top(int *a_size, t_node **a, int *max_idx, int *max_top);
// int		swap_flg(int a_size, int max_top, int next_max_idx);

#endif
