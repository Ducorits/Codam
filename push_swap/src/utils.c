/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:57 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/12 21:24:40 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>


void	add_to_bottom(t_stack *stack, t_link *new)
{
	if (stack->bottom == 0 && stack->top == 0)
	{
		stack->bottom = new;
		stack->top = new;
	}
	else
	{
		ft_printf("here? %p\n", stack->bottom);
		new->previous = stack->bottom;
		stack->bottom->next = new;
		stack->bottom = new;
	}
}

void	*fill_stack(t_stack *stack, char **argv)
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
	return (stack);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
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
