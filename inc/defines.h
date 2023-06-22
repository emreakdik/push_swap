/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:58:53 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:29:04 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// Defines
# define MIN_BLOCK_SIZE 25
# define MAX_BLOCK_SIZE 62
# define STACKA 0
# define STACKB 1
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define BUFFER_SIZE 1000

// Structers

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_box
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				stack_size;
}					t_box;

#endif
