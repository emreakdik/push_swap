/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:12:56 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:29:19 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include <stdlib.h>
#include <unistd.h>

void	pa(t_box *box, int flag)
{
	t_stack	*stack_orgtop;
	t_stack	**org;
	t_stack	**dest;

	org = &box->stack_b;
	dest = &box->stack_a;
	if (*org == NULL)
		return ;
	stack_orgtop = (*org)->next;
	if (*dest == NULL)
		(*org)->next = NULL;
	else
	{
		(*org)->next = *dest;
		(*dest)->prev = (*org);
	}
	*dest = *org;
	*org = stack_orgtop;
	if (*org)
		(*org)->prev = NULL;
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_box *box, int flag)
{
	t_stack	*stack_orgtop;
	t_stack	**org;
	t_stack	**dest;

	org = &box->stack_a;
	dest = &box->stack_b;
	if (*org == NULL)
		return ;
	stack_orgtop = (*org)->next;
	if (*dest == NULL)
		(*org)->next = NULL;
	else
	{
		(*org)->next = *dest;
		(*dest)->prev = (*org);
	}
	*dest = *org;
	*org = stack_orgtop;
	if (*org)
		(*org)->prev = NULL;
	if (flag)
		write(1, "pb\n", 3);
}
