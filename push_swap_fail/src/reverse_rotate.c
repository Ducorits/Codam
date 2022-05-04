/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 15:41:10 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/04 17:21:25 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rev_rotate(t_stack *stack)
{
	if (stack->top != 0)
	{
		stack->top->previous = stack->bottom;
		stack->bottom->next = stack->top;
		stack->top = stack->top->previous;
		stack->bottom = stack->bottom->previous;
		stack->bottom->next = 0;
		stack->top->previous = 0;
	}
}

void	rra(t_stack *stack_a)
{
	rev_rotate(stack_a);
	write(2, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	rev_rotate(stack_b);
	write(2, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(2, "rrr\n", 4);
}
