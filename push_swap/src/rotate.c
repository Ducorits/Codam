/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 19:25:12 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/14 19:36:00 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_link **stack)
{
	*stack = (*stack)->next;
}

void	rotate_both(t_link **stack_1, t_link **stack_2)
{
	*stack_1 = (*stack_1)->next;
	*stack_2 = (*stack_2)->next;
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
