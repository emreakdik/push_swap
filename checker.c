/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:32:43 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:27:27 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "instructions.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_error(t_box *box, int num)
{
	free_box(box);
	if (num)
		write(1, "Error\n", 6);
	exit(1);
}

static void	exec_instruction(t_box *box, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		sa(box, 0);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(box, 0);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(box, 0);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(box, 0);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(box, 0);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(box, 0);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(box, 0);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(box, 0);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(box, 0);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa(box, 0);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(box, 0);
	else
		free_error(box, 1);
}

static void	ft_checkchecker(t_box *box)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		exec_instruction(box, str);
		free(str);
		str = get_next_line(0);
	}
	if (check_sort(box->stack_a) && box->stack_b == NULL)
		write(1, "\033[0;32mOK\n", 10);
	else
		write(1, "\033[0;32mKO\n", 10);
	free_error(box, 0);
}

int	main(int ac, char **av)
{
	t_box	*box;

	if (ac < 2)
		return (0);
	if (!check_args(ac, av))
		ft_error("Error\n");
	create_stacks(&box, ac, av);
	if (check_sort(box->stack_a))
		return (0);
	ft_checkchecker(box);
	return (0);
}
