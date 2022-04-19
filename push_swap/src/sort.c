/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 14:34:01 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/19 15:39:49 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <unistd.h>

void	divide(int average, int lowest, t_link **stack_a, t_link **stack_b)
{
	t_link	*tmp;

	tmp = *stack_a;
	while ((*stack_a)->next != tmp)
	{
		if ((*stack_a)->content < average)
		{
			push(stack_a, stack_b);
			write(2, "pb\n", 3);
		}
		rotate(stack_a);
		write(2, "sa\n", 3);
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
	tmp = 0;
	average = 0;
	while (tmp != (*stack_a)->previous)
	{
		if (tmp == 0)
			tmp = *stack_a;
		else
		{
			if (tmp->content > highest)
				highest = tmp->content;
			if (tmp->content < lowest)
				lowest = tmp->content;
			average += tmp->content;
			tmp = tmp->next;
		}
	}
	average /= (argc - 1);
	ft_printf("%i\n", average);
	divide(average, lowest, stack_a, stack_b);
	return (average);
}
