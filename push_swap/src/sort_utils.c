/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 21:41:48 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/11 21:42:24 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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