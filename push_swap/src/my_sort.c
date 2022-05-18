/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_sort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 14:28:59 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/18 19:00:24 by dritsema      ########   odam.nl         */
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

// /*	Filter everything higher than the average.
// 	everything that matches the filter gets pushed to stack a. */
// static int	filter_high(t_link **stack_a, t_link **stack_b, int size)
// {
// 	int				i;
// 	int				count;
// 	unsigned int	average;

// 	i = 0;
// 	count = 0;
// 	average = get_average_index(stack_b, size);
// 	while (i < size)
// 	{
// 		if ((*stack_b)->index > average)
// 		{
// 			pa(stack_a, stack_b);
// 			count++;
// 		}
// 		else
// 			rb(stack_b);
// 		i++;
// 	}
// 	return (count);
// }

void	count_moves(t_link **stack_a, t_link **stack_b, int size)
{
	t_link	*tmp_a;
	t_link	*tmp_b;
	int		index_a;
	int		index_b;

	index_b = 0;
	tmp_b = *stack_b;
	if (*stack_b)
	{
		while (tmp_b->next != *stack_b)
		{
			tmp_a = *stack_a;
			tmp_b->rotate_a = 0;
			if (index_b >= size / 2)
				tmp_b->rotate_b = (size - index_b - 1) * -1;
			else
				tmp_b->rotate_b = index_b;
			if (tmp_a)
			{
				index_a = 0;
				while (tmp_a->next != *stack_a)
				{
					if (tmp_a->index > tmp_b->index)
					{
						if (index_a >= size / 2)
							tmp_b->rotate_a = (size - index_a - 1) * -1;
						else
							tmp_b->rotate_a = index_a;
						break ;
					}
					index_a++;
					tmp_a = tmp_a->next;
				}
			}
			index_b++;
			tmp_b = tmp_b->next;
		}
	}
}

unsigned int	best_to_move(t_link **stack_a, t_link **stack_b)
{
	t_link			*tmp;
	unsigned int	best_to_move;
	int				weight;
	int				least_weight;

	tmp = *stack_b;
	while (tmp->next != *stack_b)
	{
		weight = tmp->rotate_b;
		if (tmp->rotate_b >= 0)
		{
			if (tmp->rotate_a >= tmp->rotate_b)
				weight = tmp->rotate_a;
		}
		tmp = tmp->next;
	}
}

void	do_best_moves(t_link **stack_a, t_link **stack_b)
{

}

void	print_move(t_link **stack_b)
{
	t_link	*tmp;

	tmp = *stack_b;
	ft_printf("stack_b move info:\n");
	while (tmp->next != *stack_b)
	{
		ft_printf("- %i	: rotate_a: %i, rotate_b: %i\n", tmp->index, tmp->rotate_a, tmp->rotate_b);
		tmp = tmp->next;
	}
}

/*	Move all indexes that are above the average index from stack a to stack b.
	Update average index and repeat untill stack a is a size we can easily sort.
	Sort stack a and move everything back in chunks. */
void	my_sort(t_link **stack_a, t_link **stack_b, int size)
{
	int	filter_size;

	filter_size = size;
	while (*stack_a)
	{
		filter_size -= filter_low(stack_a, stack_b, filter_size);
	}
	while (*stack_b)
	{
		count_moves(stack_a, stack_b, size);
		best_to_move(stack_a, stack_b);
		do_best_moves(stack_a, stack_b);
		size--;
	}
	// print_move(stack_b);
}
