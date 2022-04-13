/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:57 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/13 19:52:50 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>


void	add_to_bottom(t_link **stack, t_link *new)
{
	if ((*stack)->next == 0 && (*stack)->previous == 0)
	{
		// ft_printf("stack equaled 0\n");
		(*stack)->next = new;
		(*stack)->previous = new;
		new->next = *stack;
		new->previous = *stack;
	}
	else
	{
		// ft_printf("here? %p\n", stack->previous);
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



void	fill_stack(t_link **stack, char **argv)
{
	int		i;
	t_link	*link;

	i = 0;
	while (argv[i + 1])
	{
		link = malloc(sizeof(t_link));
		link->content = ft_atoi(argv[i + 1]);
		add_to_bottom(stack, link);
		i++;
	}
}

// t_stack	*init_stack(void)
// {
// 	t_stack	*stack;

// 	stack = malloc(sizeof(t_stack));
// 	stack->bottom = 0;
// 	stack->top = 0;
// 	return (stack);
// }

t_link	*init_stack(void)
{
	t_link	*stack;

	stack = malloc(sizeof(t_link));
	if (stack == 0)
		return (0);
	stack->next = 0;
	stack->previous = 0;
	return (stack);
}


// int	error_check(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		i++;
// 	}
// }

// void	freestack(t_link **stack);
// {
	
// }
