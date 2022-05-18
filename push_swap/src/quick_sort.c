/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 14:28:59 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/16 16:58:46 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

/*	Filter everything lower than the average.
	everything that matches the filter gets pushed to stack b. */
static int	filter_low(t_link **stack_a, t_link **stack_b, int size)
{
	int				i;
	int				count;
	unsigned int	average;

	i = 0;
	count = 0;
	average = get_average_index(stack_a, size);
	while (i < size)
	{
		if ((*stack_a)->index <= average)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
		i++;
	}
	return (count);
}

/*	Filter everything higher than the average.
	everything that matches the filter gets pushed to stack a. */
static int	filter_high(t_link **stack_a, t_link **stack_b, int size)
{
	int				i;
	int				count;
	unsigned int	average;

	i = 0;
	count = 0;
	average = get_average_index(stack_b, size);
	while (i < size)
	{
		if ((*stack_b)->index > average)
		{
			pa(stack_a, stack_b);
			count++;
		}
		else
			rb(stack_b);
		i++;
	}
	return (count);
}

void	recurb(t_link **stack_a, t_link **stack_b, int size)
{
	int	pushed;

	pushed = filter_high(stack_a, stack_b, size);
	reverse_b(stack_b, size - pushed);
	if (pushed > SUBSIZE)
		recura(stack_a, stack_b, pushed);
	if (size - pushed > SUBSIZE)
		recurb(stack_a, stack_b, size - pushed);
	else
		push_to_a(stack_a, stack_b, size - pushed);
}

void	recura(t_link **stack_a, t_link **stack_b, int size)
{
	int	pushed;

	pushed = filter_low(stack_a, stack_b, size);
	reverse_a(stack_a, size - pushed);
	if (size - pushed > SUBSIZE)
		recura(stack_a, stack_b, size - pushed);
	if (pushed > SUBSIZE)
		recurb(stack_a, stack_b, pushed);
	else
		push_to_a(stack_a, stack_b, pushed);
}

/*	Move all indexes that are above the average index from stack a to stack b.
	Update average index and repeat untill stack a is a size we can easily sort.
	Sort stack a and move everything back in chunks. */
void	quick_sort(t_link **stack_a, t_link **stack_b, int size)
{
	int	pushed;

	pushed = filter_low(stack_a, stack_b, size);
	if (size - pushed > SUBSIZE)
		quick_sort(stack_a, stack_b, size - pushed);
	if (pushed > SUBSIZE)
		recurb(stack_a, stack_b, pushed);
	else
		push_to_a(stack_a, stack_b, pushed);
}
