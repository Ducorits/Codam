/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:53 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/02 19:09:15 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include "ft_printf.h" // for testing

void	swap(t_link **stack)
{
	int	tmp;

	if (*stack != 0 && (*stack)->next != *stack)
	{
		tmp = (*stack)->next->content;
		(*stack)->next->content = (*stack)->content;
		(*stack)->content = tmp;
	}
}

void	sa(t_link **stack_a)
{
	swap(stack_a);
	write(2, "sa\n", 3);
}

void	sb(t_link **stack_b)
{
	swap(stack_b);
	write(2, "sb\n", 3);
}

void	ss(t_link **stack_a, t_link **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(2, "ss\n", 3);
}
