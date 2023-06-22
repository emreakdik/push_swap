/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:03:18 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:28:52 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
# include "defines.h"

void	sa(t_box *box, int flag);
void	sb(t_box *box, int flag);
void	ss(t_box *box, int flag);
void	pa(t_box *box, int flag);
void	pb(t_box *box, int flag);
void	ra(t_box *box, int flag);
void	rb(t_box *box, int flag);
void	rr(t_box *box, int flag);
void	rra(t_box *box, int flag);
void	rrb(t_box *box, int flag);
void	rrr(t_box *box, int flag);

#endif
