/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 21:38:38 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/12 12:51:59 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

/*
	Filter based on the average.
	everything lower than the average.
	everything that matches the filter gets pushed to stack b.
*/
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

void	filter_a(t_link **stack_a, t_link **stack_b, int size)
{
	int	pushed;

	ft_printf("filter_a\n");
	if (size > SUBSIZE)
	{
		pushed = filter_low(stack_a, stack_b, size);
		reverse_a(stack_a, size - pushed);
		if (size - pushed > SUBSIZE)
			filter_a(stack_a, stack_b, size - pushed);
		if (pushed > SUBSIZE)
			filter_b(stack_a, stack_b, pushed);
		push_to_a(stack_a, stack_b, pushed);
	}
}

void	filter_b(t_link **stack_a, t_link **stack_b, int size)
{
	int	pushed;

	ft_printf("filter_b\n");
	if (size > SUBSIZE)
	{
		pushed = filter_high(stack_a, stack_b, size);
		reverse_b(stack_b, size - pushed);
		if (size - pushed > SUBSIZE)
			filter_b(stack_a, stack_b, size - pushed);
		if (pushed > SUBSIZE)
			filter_a(stack_a, stack_b, pushed);
		push_to_b(stack_a, stack_b, pushed);
	}
}

/*
Move all indexes that are above the average index from stack a to stack b.
Update average index and repeat untill stack a is a size we can easily sort.
Sort stack a and move 
*/
void	quick_sort2(t_link **stack_a, t_link **stack_b, int size_a)
{
	// int	size_b;
	int	new_size;
	int	pushed;

	// size_b = 0;
	new_size = size_a;
	while (new_size > SUBSIZE)
	{
		pushed = filter_low(stack_a, stack_b, new_size);
		new_size -= pushed;
		if (pushed > SUBSIZE)
			filter_b(stack_a, stack_b, pushed);
	}
	// recur(stack_a, stack_b, size_a, size_b);
}
