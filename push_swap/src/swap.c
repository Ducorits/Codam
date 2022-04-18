/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:53 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/18 20:24:53 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_link **stack)
{
	int	tmp;

	tmp = (*stack)->next->content;
	(*stack)->next->content = (*stack)->content;
	(*stack)->content = tmp;
}

void	swap_both(t_link **stack_1, t_link **stack_2)
{
	int	tmp;

	tmp = (*stack_1)->next->content;
	(*stack_1)->next->content = (*stack_1)->content;
	(*stack_1)->content = tmp;
	tmp = (*stack_2)->next->content;
	(*stack_2)->next->content = (*stack_2)->content;
	(*stack_2)->content = tmp;
}
