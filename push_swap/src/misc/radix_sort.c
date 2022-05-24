/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 14:26:37 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/24 14:30:57 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	empty_b(t_link **stack_a, t_link **stack_b)
{
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}

void	radix_sort(t_link **stack_a, t_link **stack_b, int argc)
{
	int	size;
	int	i;
	int	tmp;
	int	shift;

	size = argc - 1;
	shift = 0;
	while (check_sorted(stack_a, 0) == 0)
	{
		i = 0;
		while (i < size && check_sorted(stack_a, 0) == 0)
		{
			tmp = (*stack_a)->index;
			if (tmp >> shift & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		shift += 1;
		empty_b(stack_a, stack_b);
	}
}
