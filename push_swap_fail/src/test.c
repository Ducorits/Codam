/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 14:01:44 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/04 18:57:49 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a);
	print_stack(stack_b);
}

void	print_stack(t_stack *stack)
{
	t_link	*tmp;

	if (stack->top != 0)
	{
		tmp = stack->top;
		while (tmp != 0)
		{
			ft_printf("Stack_a: %i\n", tmp->content);
			tmp = tmp->next;
		}
	}
}

int	check_sorted(t_stack *stack, int size)
{
	t_link	*tmp;

	size -= 1;
	if (stack->top != 0)
	{
		tmp = stack->top;
		while (tmp->next != 0)
		{
			if (tmp->content > tmp->next->content)
			{
				ft_printf("tmp > tmp->next, size:%i\n", size);
				return (0);
			}
			tmp = tmp->next;
		}
	}
	return (1);
}
