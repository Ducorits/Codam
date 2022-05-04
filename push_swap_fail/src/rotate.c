/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 19:25:12 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/04 17:17:29 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rotate(t_stack *stack)
{
	if (stack->top != 0)
	{
		stack->top->previous = stack->bottom;
		stack->bottom->next = stack->top;
		stack->top = stack->top->next;
		stack->bottom = stack->bottom->next;
		stack->bottom->next = 0;
		stack->top->previous = 0;
	}
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(2, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(2, "ra\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(2, "rr\n", 3);
}
