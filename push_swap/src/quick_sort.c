/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 14:28:59 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/09 18:27:09 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	get_average_index(t_link **stack, int size)
{
	t_link			*tmp;
	unsigned int	average;
	int				i;

	tmp = *stack;
	i = 0;
	average = 0;
	while (i < size)
	{
		average += tmp->index;
		tmp = tmp->next;
		i++;
	}
	average /= size;
	return (average);
}

/*
	Filter based on the average.
	dir 0 is everything lower than the average.
	everything that matches the filter gets pushed to stack b.
*/
int	filter_low(t_link **stack_a, t_link **stack_b, int size)
{
	int				i;
	int				count;
	unsigned int	average;

	i = 0;
	count = 0;
	average = get_average_index(stack_a, size);
	while (i < size)
	{
		if ((*stack_a)->index < average)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
		i++;
	}
	return (size - count);
}

// static void	empty_b(t_link **stack_a, t_link **stack_b)
// {
// 	while (*stack_b)
// 	{
// 		pa(stack_a, stack_b);
// 	}
// }

/*
Move all indexes that are above the average index from stack a to stack b.
Update average index and repeat untill stack a is a size we can easily sort.
Sort stack a and move 


*/
void	quick_sort(t_link **stack_a, t_link **stack_b, int size)
{
	// int	i;
	// int	mod;

	// i = size;
	if (size > 4)
	{
		size = filter_low(stack_a, stack_b, size);
		// mod = size % 2;
		// size /= 2;
		// size += mod;
		quick_sort(stack_a, stack_b, size);

	}
}
