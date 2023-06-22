/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:19:49 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:28:16 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "instructions.h"
#include "push_swap.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	free_box(t_box *box)
{
	t_stack	*tmp;

	while (box->stack_a)
	{
		tmp = box->stack_a;
		box->stack_a = box->stack_a->next;
		free(tmp);
	}
	while (box->stack_b)
	{
		tmp = box->stack_b;
		box->stack_b = box->stack_b->next;
		free(tmp);
	}
	free(box);
}

int	get_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(0);
}
