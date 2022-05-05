/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 14:34:01 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/05 22:30:12 by dritsema      ########   odam.nl         */
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

// void	sort_indexes(t_link **stack_a, int argc)
// {
// 	t_link	*tmp;
// 	int		*values;
// 	int		lowest;
// 	int		highest;

// 	values = malloc(sizeof(int) * argc - 1);
// 	tmp = *stack_a;
// 	while ()
// 	while (tmp != (*stack_a)->previous)
// 	{
// 		if (tmp->content > highest)
// 			highest = tmp->content;
// 		if (tmp->content < lowest)
// 			lowest = tmp->content;
// 		tmp = tmp->next;
// 	}
// }

int	sort(t_link **stack_a, t_link **stack_b, int argc)
{
	int		highest;
	int		lowest;
	long	average;
	t_link	*tmp;
	int		

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
