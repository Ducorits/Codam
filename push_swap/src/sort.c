/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 14:34:01 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/07 16:30:12 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <unistd.h>

void	divide(int average, t_link **stack_a, t_link **stack_b)
{
	t_link	*tmp;

	tmp = *stack_a;
	while (1)
	{
		ft_printf("current content: %i\n", (*stack_a)->content);
		if ((*stack_a)->content < average)
		{
			pb(stack_a, stack_b);
		}
		if ((*stack_a)->next == tmp)
			break ;
		ra(stack_a);
	}
}

void	bad_sort(int average, t_link **stack_a, t_link **stack_b, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		ft_printf("Stack_a current: %i\n", (*stack_a)->content);
		if ((*stack_a)->content <= average)
		{
			pb(stack_a, stack_b);
			size--;
		}
		else
			ra(stack_a);
		i++;
	}
}

void	push_lowest(t_link **copy_a, t_link **copy_b, t_link *lowest)
{
	while ((*copy_a)->index != lowest->index)
	{
		ft_printf("copy_a index: %i Lowest index: %i\n", (*copy_a)->index, lowest->index);
		*copy_a = (*copy_a)->next;
	}
	push(copy_a, copy_b);
}

void	sort_indexes(t_link **copy_a, t_link **copy_b, int argc)
{
	t_link	*tmp;
	t_link	*lowest;
	int		i;
	int		j;

	i = 0;
	tmp = *copy_a;
	while (i < argc - 1)
	{	
		j = 0 + i;
		while (tmp != (*copy_a)->previous)
		{
			if (tmp->content < lowest->content)
			{
				lowest = tmp;
			}
			ft_printf("tmp: %p\n", tmp);
			tmp = tmp->next;
			j++;
		}
		push_lowest(copy_a, copy_b, lowest);
		i++;
		print_stack(copy_b);
	}
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
	radix_sort(stack_a, stack_b, argc, highest);
	// bubble_sort(stack_a, argc);
	// bad_sort(average, stack_a, stack_b, argc - 1);
	// divide(average, stack_a, stack_b);
	return (average);
}
