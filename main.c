/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:09:27 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/20 22:56:47 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	get_index(box->stack_a);
	sort(box);
	free_box(box);
	return (0);
}
