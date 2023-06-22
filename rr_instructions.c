/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:05:17 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:28:25 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "stack_utils.h"
#include <stdlib.h>
#include <unistd.h>

static void	rr(t_stack *stack)
{
	int	num;
	int	index;

	if (!stack)
		return ;
	stack = stack_last(stack);
	num = stack->value;
	index = stack->index;
	while (stack)
	{
		if (stack->prev == NULL)
		{
			stack->value = num;
			stack->index = index;
		}
		else
		{
			stack->value = stack->prev->value;
			stack->index = stack->prev->index;
		}
		stack = stack->prev;
	}
}

void	rra(t_box *box, int flag)
{
	rr(box->stack_a);
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_box *box, int flag)
{
	rr(box->stack_b);
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_box *box, int flag)
{
	rr(box->stack_a);
	rr(box->stack_b);
	if (flag)
		write(1, "rrr\n", 4);
}
