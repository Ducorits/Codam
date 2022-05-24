/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 14:25:30 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/24 14:25:44 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_link **stack_a, t_link **stack_b, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		pb(stack_a, stack_b);
		i++;
	}
}

void	push_to_a(t_link **stack_a, t_link **stack_b, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		pa(stack_a, stack_b);
		i++;
	}
}

void	reverse_b(t_link **stack_b, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		rrb(stack_b);
		i++;
	}
}

void	reverse_a(t_link **stack_a, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		rra(stack_a);
		i++;
	}
}
