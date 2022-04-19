/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 15:41:10 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/19 15:44:44 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_link **stack_a)
{
	rev_rotate(stack_a);
	write(2, "rra\n", 4);
}

void	rrb(t_link **stack_b)
{
	rev_rotate(stack_b);
	write(2, "rrb\n", 4);
}

void	rrr(t_link **stack_a, t_link **stack_b)
{
	rev_rotate_both(stack_a, stack_b);
	write(2, "rrr\n", 4);
}

void	rev_rotate(t_link **stack)
{
	*stack = (*stack)->previous;
}

void	rev_rotate_both(t_link **stack_1, t_link **stack_2)
{
	*stack_1 = (*stack_1)->previous;
	*stack_2 = (*stack_2)->previous;
}
