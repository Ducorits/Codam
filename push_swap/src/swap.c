/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:53 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/14 21:17:00 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_link **stack)
{
	(*stack)->next->previous = (*stack)->previous;
	(*stack)->previous->next = (*stack)->next;
	(*stack)->previous = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->previous->next = *stack;
	(*stack)->next->previous = *stack;
	*stack =  (*stack)->previous;
}