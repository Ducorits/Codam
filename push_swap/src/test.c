/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 14:01:44 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/05 16:11:00 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	print_stacks(t_link **stack_a, t_link **stack_b)
{
	ft_printf("\nStack_a:\n");
	print_stack(stack_a);
	ft_printf("\nStack_B:\n");
	print_stack(stack_b);
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
			ft_printf("- %i\n", tmp->content);
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
				return (0);
			}
			tmp = tmp->next;
			i++;
		}
	}
	return (1);
}
