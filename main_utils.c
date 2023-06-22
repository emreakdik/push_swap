/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:42:23 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:27:53 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "push_swap.h"
#include "stack_utils.h"

int	check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			return (0);
		if (ft_contains(tmp, args, i))
			return (0);
		if (tmp < MIN_INT || tmp > MAX_INT)
			return (0);
		i++;
	}
	if (ac == 2)
		ft_free(args);
	return (1);
}

void	create_stacks(t_box **box, int ac, char **av)
{
	t_stack	*new;
	char	**args;
	int		i;

	*box = (t_box *)malloc(sizeof(t_box));
	(*box)->stack_a = NULL;
	(*box)->stack_b = NULL;
	(*box)->stack_size = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	i = 0;
	while (args[i])
	{
		new = stack_new(ft_atoi(args[i]));
		stack_add_back(&(*box)->stack_a, new);
		(*box)->stack_size++;
		i++;
	}
	if (ac == 2)
		ft_free(args);
}

void	get_index(t_stack *stack)
{
	int		index;
	t_stack	*top;
	t_stack	*tmp;

	index = 0;
	top = stack;
	while (stack)
	{
		tmp = top;
		while (tmp)
		{
			if (tmp->value < stack->value)
				index++;
			tmp = tmp->next;
		}
		stack->index = index;
		stack = stack->next;
		index = 0;
	}
}

int	check_sort(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	check_duplication(int ac, char **av, int i)
{
	int	j;

	j = 1;
	while (j < ac)
	{
		if (i != j && ft_atoi(av[i]) == ft_atoi(av[j]))
			return (0);
		j++;
	}
	return (1);
}
