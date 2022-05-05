/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:36:02 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/05 14:30:07 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	bubble_sort(t_link **stack_a, int argc)
{
	int	size;
	int	i;

	size = argc - 1;
	while (check_sorted(stack_a, size) == 0)
	{
		i = 0;
		ft_printf("Not sorted\n");
		while (i < size)
		{
			print_stack(stack_a);
			if ((*stack_a)->content > (*stack_a)->next->content
				&& i != size - 1)
			{
				sa(stack_a);
			}
			ra(stack_a);
			i++;
		}
		print_stack(stack_a);
	}
	ft_printf("It's sorted you good bro\n");
}
