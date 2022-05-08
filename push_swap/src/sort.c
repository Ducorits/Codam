/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 14:34:01 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/08 15:27:11 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <unistd.h>

void	update_indexes(t_link **stack_a, t_link **copy_a, int size)
{
	t_link	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (i < size)
	{
		while (tmp->content != (*copy_a)->content)
		{
			tmp = tmp->next;
		}
		tmp->index = (*copy_a)->index;
		*copy_a = (*copy_a)->next;
		i++;
	}
}

void	push_lowest(t_link **copy_a, t_link **copy_b, t_link *lowest)
{
	while (*copy_a != lowest)
	{
		*copy_a = (*copy_a)->next;
	}
	// ft_printf("pushed lowest\n");
	push(copy_a, copy_b);
}

void	empty_to_stack(t_link **a, t_link **b, int size)
{
	int	i;

	i = size - 1;
	while (*a)
	{
		(*a)->index = i;
		push(a, b);
		i--;
	}
}

void	sort_indexes(t_link **copy_a, t_link **copy_b, int size)
{
	t_link	*tmp;
	t_link	*lowest;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{	
		j = 0 + i;
		tmp = *copy_a;
		lowest = *copy_a;
		while (j < size)
		{
			if (tmp->content < lowest->content)
			{
				lowest = tmp;
				// ft_printf("update lowest to: %i\n", lowest->content);
			}
			// ft_printf("j: %i size:%i\n", j, size);
			tmp = tmp->next;
			j++;
		}
		push_lowest(copy_a, copy_b, lowest);
		i++;
		// print_stack(copy_b);
	}
	empty_to_stack(copy_b, copy_a, size);
	// ft_printf("copy_a:\n");
	// print_stack(copy_a);
}

int	sort(t_link **stack_a, t_link **stack_b, int argc)
{
	int		highest;
	int		lowest;
	long	average;
	t_link	*tmp;

	highest = 0;
	lowest = 0;
	average = 0;
	tmp = *stack_a;
	while (tmp != (*stack_a)->previous)
	{
		if (tmp->content > highest)
			highest = tmp->content;
		if (tmp->content < lowest)
			lowest = tmp->content;
		average += tmp->content;
		tmp = tmp->next;
	}
	average /= (argc - 1);
	// ft_printf("%i\n", average);
	radix_sort(stack_a, stack_b, argc);
	// bubble_sort(stack_a, argc);
	// bad_sort(average, stack_a, stack_b, argc - 1);
	// divide(average, stack_a, stack_b);
	return (average);
}
