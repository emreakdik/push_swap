/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:38:20 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:28:09 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*stack_last(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack)
	{
		last = stack_last(*stack);
		last->next = new;
		new->prev = last;
	}
	else
		*stack = new;
}

int	are_values(t_stack *stack, int key_nbr)
{
	while (stack)
	{
		if (stack->index < key_nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}
