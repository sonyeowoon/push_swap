/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:07:16 by sangseo           #+#    #+#             */
/*   Updated: 2024/08/14 18:46:08 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chk_arg(char **av)
{
	int	i;
	int	flg;

	flg = 0;
	while (*(++av))
	{
		i = -1;
		while ((*av)[++i])
		{
			if (flg != 1 && ft_isspace((*av)[i]))
				flg = 0;
			else if (flg > 0 && !(ft_isdigit((*av)[i])))
				return (0);
			else if ((*av)[i] == '+' || (*av)[i] == '-')
				flg = 1;
			else if (ft_isdigit((*av)[i]))
				flg = 2;
			else
				return (0);
		}
		if (flg == 1)
			return (0);
		flg = 0;
	}
	return (1);
}

void	push_swap(t_node *a)
{
	int		d;
	t_node	*b;

	b = 0;
	d = chk_dupnsort(a);
	if (d == -1)
		ft_error(a);
	if (d == 1)
		stack_free(a);
	if (d == 0)
	{
		if (chk_ascending(a))
			min_to_top(&a, ft_lstsize(a));
		else
			ft_sorting(a, b);
	}
	/*
	int	d;
	t_node	*b;
	t_node	*temp;

	b = 0;
	d = chk_dupnsort(a);

	temp = a;
	ft_printf("first a stack\n");
	while (temp)
	{
		ft_printf("%d\n", (*temp).n);
		temp = (*temp).next;
	}
	ft_printf("------------\n");

	if (d == 1)
		ft_printf("sorted\n");
	else if (d == 0)
		ft_printf("not sorted\n");
	else
		ft_printf("duplicate exists\n");
	ft_printf("------------\n");

	ft_printf("cmd\n\n");
	ft_swap("sa", &a);
	ft_push("pb", &a, &b);
	ft_swap("sa", &a);
	ft_push("pb", &a, &b);
	ft_swap("sb", &b);
	double_cmd("ss", &a, &b);
	ft_push("pb", &a, &b);
	ft_rotate("ra", &a);
	double_cmd("rr", &a, &b);
	ft_reverse_rotate("rra", &a);
	ft_reverse_rotate("rrb", &b);
	double_cmd("rrr", &a, &b);
	ft_printf("------------\n");

	ft_printf("stack A\n\n");
	temp = a;
	while (temp)
	{
		ft_printf("%d\n", (*temp).n);
		temp = (*temp).next;
	}
	ft_printf("\n------------\n");
	ft_printf("stack B\n\n");
	temp = b;
	while (temp)
	{
		ft_printf("%d\n", (*temp).n);
		temp = (*temp).next;
	}
	ft_printf("\n------------\n");
	*/
}

int	main(int ac, char **av)
{
	t_node	*a;

	a = 0;
	if (ac < 2)
		return (0);
	if (chk_arg(av) == 0)
		ft_error(a);
	a = make_stack(av);
	if (a == 0)
		ft_error(a);
	push_swap(a);
	return (0);
	/*
	int		c;
	t_node	*a;

	if (ac < 2)
		return (0);
	if (chk_arg(av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("success\n");
	a = make_stack(av);
	if (a == 0)
	{
		ft_error(a);
	}
	push_swap(a);

	return (0);
	*/
}
/*
int	main()
{
	int	c;

	int argc;
	char **argv;

	argv = (char **)malloc(sizeof(char *) * 4);
	argv[0] = (char *)malloc(sizeof(char));
	argv[1] = (char *)malloc(sizeof(char) * 2);
	argv[2] = (char *)malloc(sizeof(char) * 2);
	argv[3] = (char *)malloc(sizeof(char) * 3);
	argc = 4;
	argv[0][0] = 0;
	argv[1][0] = '3';
	argv[1][1] = 0;
	argv[2][0] = '2';
	argv[2][1] = 0;
	argv[3][0] = '-';
	argv[3][1] = '1';
	argv[3][2] = 0;

	c = chk_arg(argc, argv);
	if (c == -1)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (c == 0)
		return (0);
	else
		ft_printf("success\n");
	return (0);
}
*/
