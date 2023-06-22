/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:43:40 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/21 17:24:29 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "instructions.h"
#include "push_swap.h"
#include "stack_utils.h"

void	prepare_to_sort(t_box *box, int num_slot, int slot_size)
{
	int	key_nbr;
	int	r_hold;

	r_hold = 0;
	key_nbr = slot_size * num_slot;
	while (are_values(box->stack_a, key_nbr))
	{
		if (box->stack_a->index < key_nbr)
		{
			if (r_hold == 1)
				r_hold = rb_or_rr(box, 0);
			if (box->stack_a->index < (key_nbr - (slot_size / 2)))
				r_hold = push_b_hold(box);
			else
				pb(box, 1);
		}
		else
		{
			if (r_hold == 1)
				r_hold = rb_or_rr(box, 1);
			else
				ra(box, 1);
		}
	}
}

void	sort_three(t_box *box)
{
	t_stack	*stack;
	int		index;

	stack = box->stack_a;
	index = get_min_index(stack);
	if (stack->index == index + 1 && stack->next->index == index
		&& stack->next->next->index == index + 2)
		sa(box, 1);
	if (stack->index == index + 2 && stack->next->index == index + 1
		&& stack->next->next->index == index)
		sa_ra(box, 1);
	if (stack->index == index + 2 && stack->next->index == index
		&& stack->next->next->index == index + 1)
		ra(box, 1);
	if (stack->index == index && stack->next->index == index + 2
		&& stack->next->next->index == index + 1)
		sa_ra(box, 0);
	if (stack->index == index + 1 && stack->next->index == index + 2
		&& stack->next->next->index == index)
		rra(box, 1);
}

void	sort(t_box *box)
{
	if (box->stack_size < 3)
		sa(box, 1);
	else if (box->stack_size < 4)
		sort_three(box);
	else if (box->stack_size < MIN_BLOCK_SIZE)
	{
		prepare_to_sort(box, 1, (box->stack_size - 3));
		sort_three(box);
		adjusted_sort(box);
	}
	else
		big_sort(box);
}

void	adjusted_sort(t_box *box)
{
	int		index;
	int		close_index;
	int		position;
	int		swap;
	t_stack	*stack;

	stack = box->stack_b;
	while (stack)
	{
		get_close_index(box, &index, &close_index, &position);
		swap = 0;
		while (stack->index != index)
		{
			if (stack->index == close_index)
				swap = push_close_value(box, &stack, index, &position);
			best_rr(box, position, STACKB);
		}
		stack = push_side(box, STACKB);
		if (swap)
			sa(box, 1);
	}
}

void	big_sort(t_box *box)
{
	int	i;
	int	slots;
	int	slot_size;

	slot_size = MIN_BLOCK_SIZE;
	if (box->stack_size > 250)
		slot_size = MAX_BLOCK_SIZE;
	slots = (box->stack_size / slot_size);
	if (box->stack_size % slot_size > 0)
		slots++;
	i = 1;
	while (i <= slots)
	{
		prepare_to_sort(box, i, slot_size);
		i++;
	}
	adjusted_sort(box);
}
