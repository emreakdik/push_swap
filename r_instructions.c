/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:08:08 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:29:41 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include <stdlib.h>
#include <unistd.h>

static void	r(t_stack *stack)
{
	int	value;
	int	index;

	if (!stack)
		return ;
	value = stack->value;
	index = stack->index;
	while (stack)
	{
		if (stack->next == NULL)
		{
			stack->value = value;
			stack->index = index;
		}
		else
		{
			stack->value = stack->next->value;
			stack->index = stack->next->index;
		}
		stack = stack->next;
	}
}

void	ra(t_box *box, int flag)
{
	r(box->stack_a);
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_box *box, int flag)
{
	r(box->stack_b);
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_box *box, int flag)
{
	r(box->stack_a);
	r(box->stack_b);
	if (flag)
		write(1, "rr\n", 3);
}
