/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:57 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/19 14:55:49 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

void	add_to_bottom(t_link **stack, t_link *new)
{	
	if (*stack == 0)
	{
		*stack = new;
		(*stack)->next = new;
		(*stack)->previous = new;
	}
	else
	{
		new->next = *stack;
		new->previous = (*stack)->previous;
		(*stack)->previous->next = new;
		(*stack)->previous = new;
	}
}

void	add_to_top(t_link **stack, t_link *new)
{
	add_to_bottom(stack, new);
	*stack = new;
}

t_link	**make_empty_stack(void)
{
	t_link	**stack;

	stack = malloc(sizeof(t_link *));
	if (stack == 0)
		return (0);
	*stack = 0;
	return (stack);
}

t_link	**make_stack(char **argv)
{
	int		i;
	t_link	**stack;
	t_link	*link;

	stack = malloc(sizeof(t_link *));
	*stack = malloc(sizeof(t_link));
	if (*stack == 0 || stack == 0)
		return (0);
	(*stack)->content = ft_atoi(argv[1]);
	(*stack)->next = *stack;
	(*stack)->previous = *stack;
	i = 2;
	while (argv[i])
	{
		link = malloc(sizeof(t_link));
		if (link == 0)
			return (0);
		link->content = ft_atoi(argv[i]);
		add_to_bottom(stack, link);
		i++;
	}
	return (stack);
}

int	freestack(t_link **stack)
{
	t_link	*tmp;

	if (stack != 0)
	{
		if (*stack == 0)
		{
			free(stack);
		}
		else
		{
			tmp = (*stack)->previous;
			while (*stack != tmp)
			{
				(*stack) = (*stack)->next;
				free((*stack)->previous);
			}
			free(*stack);
			free(stack);
		}
		return (1);
	}
	return (0);
}
