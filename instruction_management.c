/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:09:47 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:27:50 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "instructions.h"
#include "push_swap.h"
#include "stack_utils.h"

int	rb_or_rr(t_box *box, int hold)
{
	if (hold)
		rr(box, 1);
	else
		rb(box, 1);
	return (0);
}

int	push_b_hold(t_box *box)
{
	pb(box, 1);
	return (1);
}

void	best_rr(t_box *box, int pos, int side)
{
	int	size;

	if (pos == 0)
		return ;
	size = stack_size(box->stack_a);
	if (side == STACKB)
		size = stack_size(box->stack_b);
	if (pos > (size / 2))
	{
		if (side == STACKA)
			rra(box, 1);
		else
			rrb(box, 1);
	}
	else
	{
		if (side == STACKA)
			ra(box, 1);
		else
			rb(box, 1);
	}
}
