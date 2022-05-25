/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smaller_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 15:06:41 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/25 17:25:44 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sort2(t_link **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	sort3(t_link **stack_a)
{
	if (!check_sorted(stack_a, 3))
	{
		if ((*stack_a)->index > (*stack_a)->next->index
			&& (*stack_a)->index > (*stack_a)->previous->index)
			ra(stack_a);
		else if ((*stack_a)->previous->index < (*stack_a)->index
			&& (*stack_a)->previous->index < (*stack_a)->next->index)
			rra(stack_a);
		if (!check_sorted(stack_a, 3))
			sa(stack_a);
		if (!check_sorted(stack_a, 3))
			ra(stack_a);
	}
}

void	sort5(t_link **stack_a, t_link **stack_b, int size)
{
	if (size == 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	else
		pb(stack_a, stack_b);
	sort3(stack_a);
	while (*stack_b)
	{
		update_move_count(stack_a, stack_b);
		do_best_moves(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	set_right(stack_a, size);
}

void	small_sort(t_link **stack_a, t_link **stack_b, int size)
{
	if (size == 2)
		sort2(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else
		sort5(stack_a, stack_b, size);
}
