/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:47 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/04 18:37:48 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// void	push(t_stack *stack_1, t_stack *stack_2)
// {
// 	t_link	*tmp;

// 	if (*stack_1 != 0)
// 	{
// 		if ((*stack_1)->next != *stack_1)
// 		{
// 			tmp = *stack_1;
// 			(*stack_1)->previous->next = (*stack_1)->next;
// 			(*stack_1)->next->previous = (*stack_1)->previous;
// 			*stack_1 = (*stack_1)->next;
// 			add_to_top(stack_2, tmp);
// 		}
// 		else
// 		{
// 			add_to_top(stack_2, *stack_1);
// 			*stack_1 = 0;
// 		}
// 	}
// }

// void	pa(t_stack *stack_a, t_stack *stack_b)
// {
// 	push(stack_b, stack_a);
// 	write(2, "pa\n", 3);
// }

// void	pb(t_stack *stack_a, t_stack *stack_b)
// {
// 	push(stack_a, stack_b);
// 	write(2, "pb\n", 3);
// }

void	push(t_stack *stack_1, t_stack *stack_2)
{
	t_link	*tmp;

	if (stack_1->top != 0)
	{
		tmp = stack_1->top;
		if (stack_1->top == stack_1->bottom)
			stack_1->bottom = 0;
		stack_1->top = stack_1->top->next;
		if (stack_1->top != 0)
			stack_1->top->previous = 0;
		if (stack_2->top != 0)
		{
			stack_2->top->previous = tmp;
			tmp->next = stack_2->top;
			stack_2->top = tmp;
		}
		else
		{
			tmp->next = 0;
			stack_2->top = tmp;
			stack_2->bottom = tmp;
		}
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(2, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(2, "pb\n", 3);
}
