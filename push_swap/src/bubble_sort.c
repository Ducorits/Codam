/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:36:02 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/02 19:30:15 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	bubble_sort(t_link **stack_a, int argc)
{
	int	size;
	int	i;

	size = argc - 1;
	i = 0;
	while (i < size)
	{
		print_stack(stack_a);
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			sa(stack_a);
			// print_stack(stack_a);
			// ra(stack_a);
		}
		else if (size > 2)
		{
			ra(stack_a);
		}
		i++;
	}
	ra(stack_a);
	print_stack(stack_a);
	if (check_sorted(stack_a, size) == 0)
	{
		ft_printf("check_sorted == 0\n");
		bubble_sort(stack_a, argc);
	}
}
