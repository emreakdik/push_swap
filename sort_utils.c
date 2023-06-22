/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:45:13 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/21 17:24:39 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "defines.h"
#include "instructions.h"

t_stack	*push_side(t_box *box, int side)
{
	if (side == STACKB)
	{
		pa(box, 1);
		return (box->stack_b);
	}
	else
	{
		pb(box, 1);
		return (box->stack_a);
	}
}

int	push_close_value(t_box *box, t_stack **stack, int index, int *pos)
{
	*stack = push_side(box, STACKB);
	*pos = get_position(*stack, index);
	return (1);
}

int	get_max_index(t_stack *stack)
{
	int	max_index;

	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

int	get_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack->index != index)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

void	get_close_index(t_box *box, int *index, int *close_index, int *pos)
{
	*index = get_max_index(box->stack_b);
	*close_index = *index - 1;
	*pos = get_position(box->stack_b, *index);
}
