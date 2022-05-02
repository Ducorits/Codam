/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 14:01:44 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/02 19:22:44 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	print_stacks(t_link **stack_a, t_link **stack_b)
{
	t_link	*tmp;

	tmp = 0;
	if (*stack_a != 0)
	{
		while (tmp != (*stack_a)->previous)
		{
			if (tmp == 0)
				tmp = *stack_a;
			else
				tmp = tmp->next;
			ft_printf("Stack_a: %i\n", tmp->content);
		}
	}
	if (*stack_b != 0)
	{
		tmp = 0;
		while (tmp != (*stack_b)->previous)
		{
			if (tmp == 0)
				tmp = *stack_b;
			else
				tmp = tmp->next;
			ft_printf("Stack_b: %i\n", tmp->content);
		}
	}
}

void	print_stack(t_link **stack)
{
	t_link	*tmp;

	tmp = 0;
	if (*stack != 0)
	{
		while (tmp != (*stack)->previous)
		{
			if (tmp == 0)
				tmp = *stack;
			else
				tmp = tmp->next;
			ft_printf("Stack_a: %i\n", tmp->content);
		}
	}
}

int	check_sorted(t_link **stack, int size)
{
	t_link	*tmp;
	int		i;

	size -= 1;
	i = 0;
	if (*stack != 0)
	{
		tmp = *stack;
		while (i < size)
		{
			if (tmp->content > tmp->next->content)
			{
				ft_printf("tmp > tmp->next, size:%i\n", size);
				return (0);
			}
			tmp = tmp->next;
			i++;
		}
	}
	return (1);
}
