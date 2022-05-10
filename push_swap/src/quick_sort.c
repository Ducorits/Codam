/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 14:28:59 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/10 22:45:47 by dritsema      ########   odam.nl         */
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
	everything lower than the average.
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

int	filter_high(t_link **stack_a, t_link **stack_b, int size)
{
	int				i;
	int				count;
	unsigned int	average;

	i = 0;
	count = 0;
	average = get_average_index(stack_b, size);
	// ft_printf("Size: %i Average: %i\n", size, average);
	while (i < size)
	{
		if ((*stack_b)->index > average)
		{
			// ft_printf("index: %i\n", (*stack_b))
			pa(stack_a, stack_b);
			count++;
		}
		else
			rb(stack_b);
		i++;
	}
	return (count);
}
// static void	empty_b(t_link **stack_a, t_link **stack_b)
// {
// 	while (*stack_b)
// 	{
// 		pa(stack_a, stack_b);
// 	}
// }

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

// static void	recur(t_link **stack_a, t_link **stack_b, int size_a, int size_b)
// {
// 	int	pushed;
// 	int	tmp;

// 	ft_printf("Recur\n");
// 	if (size_a > 5)
// 	{
// 		ft_printf("size_a > 5\nFilter low\n");
// 		pushed = filter_low(stack_a, stack_b, size_a);
// 		size_a -= pushed;
// 		size_b += pushed;
// 		ft_printf("pushed: %i\nsize_a: %i\nsize_b: %i\n", pushed, size_a, size_b);
// 		recur(stack_a, stack_b, size_a, size_b);
// 		ft_printf("Filter high amount: %i\n", pushed);
// 		tmp = filter_high(stack_a, stack_b, pushed);
// 		reverse_b(stack_b, pushed - tmp);
// 		if (tmp > 5)
// 		{
// 			recur(stack_a, stack_b, tmp, size_b);
// 		}
// 		ft_printf("Reverse b amount: %i\n", pushed - tmp);
// 		push_to_a(stack_a, stack_b, pushed - tmp);
// 		// size_a = filter_low(stack_a, stack_b, size_a);
// 		// reverse_a(stack_a, size_a);
// 	}
// }

static void	recur2(t_link **stack_a, t_link **stack_b, int size_a)
{
	int	pushed;
	int	tmp;

	ft_printf("Recur\n");
	if (size_a > 5)
	{
		pushed = filter_low(stack_a, stack_b, size_a);
		reverse_a(stack_a, size_a - pushed);
		size_a -= pushed;
		// size_b += pushed;
		recur2(stack_a, stack_b, size_a);
		tmp = filter_high(stack_a, stack_b, pushed);
		reverse_b(stack_b, pushed - tmp);
		if (tmp > 5)
		{
			recur2(stack_a, stack_b, tmp);
		}
	}
}

static void	recur(t_link **stack_a, t_link **stack_b, int size_a, int size_b)
{
	int	pushed;
	int	tmp;

	ft_printf("Recur\n");
	if (size_a > 5)
	{
		pushed = filter_low(stack_a, stack_b, size_a);
		size_a -= pushed;
		size_b += pushed;
		recur(stack_a, stack_b, size_a, size_b);
		tmp = filter_high(stack_a, stack_b, pushed);
		reverse_b(stack_b, pushed - tmp);
		if (tmp > 5)
		{
			recur2(stack_a, stack_b, tmp);
		}
	}
}

/*
Move all indexes that are above the average index from stack a to stack b.
Update average index and repeat untill stack a is a size we can easily sort.
Sort stack a and move 
*/
void	quick_sort(t_link **stack_a, t_link **stack_b, int size_a)
{
	int	size_b;

	size_b = 0;
	recur(stack_a, stack_b, size_a, size_b);
}
