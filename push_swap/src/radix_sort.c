/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 14:26:37 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/05 20:08:53 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	recur(int n)
{
	if (n)
	{
		recur(n / 2);
		if (n & 1)
			ft_printf("1");
		else
			ft_printf("0");
	}
}

void	print_binary(int n)
{
	if (n & (1 << 31))
	{
		ft_printf("minus?\n");
	}
	recur(n);
}

void	empty_b(t_link **stack_a, t_link **stack_b)
{
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}

void	radix_sort(t_link **stack_a, t_link **stack_b, int argc, int highest)
{
	int	size;
	int	i;
	int	tmp;
	int	shift;

	size = argc - 1;
	highest += 1;
	shift = 0;
	while (check_sorted(stack_a, size) == 0)
	{
		i = 0;
		while (i < size)
		{
			tmp = (*stack_a)->index;
			// print_binary((*stack_a)->index);
			// ft_printf("\n");
			if (tmp >> shift & 1)
			{
				// ft_printf("%u, 1\n", (*stack_a)->index);
				ra(stack_a);
			}
			else
			{
				// ft_printf("%u, 0\n", (*stack_a)->index);
				pb(stack_a, stack_b);
			}
			i++;
		}
		shift += 1;
		empty_b(stack_a, stack_b);
	}
}
