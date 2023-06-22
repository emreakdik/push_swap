/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:18:51 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:28:48 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../inc/defines.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

// Main Utils
void	create_stacks(t_box **box, int ac, char **av);

int		check_args(int ac, char **av);
int		check_sort(t_stack *stack);
int		check_duplication(int ac, char **av, int i);

void	get_index(t_stack *stack);

// Instruction Management
int		rb_or_rr(t_box *box, int hold);
int		push_b_hold(t_box *box);

void	best_rr(t_box *box, int pos, int side);

// Sort
void	prepare_to_sort(t_box *box, int num_slot, int slot_size);
void	sort_three(t_box *box);
void	sort(t_box *box);
void	adjusted_sort(t_box *box);
void	big_sort(t_box *box);

// Sort Utils
int		push_close_value(t_box *box, t_stack **stack, int index, int *pos);
int		get_max_index(t_stack *stack);
int		get_position(t_stack *stack, int index);
int		get_min_index(t_stack *stack);

t_stack	*push_side(t_box *box, int side);

void	get_close_index(t_box *box, int *index, int *close_index, int *pos);
void	sa_ra(t_box *meta, int reverse);

// Utils
void	ft_free(char **s);
void	free_box(t_box *box);
void	ft_error(char *s);
char	*get_next_line(int fd);
#endif
