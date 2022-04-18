/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:22 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/14 21:16:25 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_link	**stack_a;
	t_link	**stack_b;
	t_link	*link;
	int		i;

	if (argc > 1 && !input_error_check(argc, &argv[1]))
	{
		stack_a = make_stack(argv);
		stack_b = make_empty_stack();
		swap(stack_a);
		push(stack_a, stack_b);
		push(stack_a, stack_b);
		
		i = 0;
		link = 0;
		while (link != (*stack_a)->next)
		{
			if (link)
				link = link->previous;
			else
				link = *stack_a;
			printf("stack a pos %i: %i\n", i, link->content);
			i++;
		}
		link = 0;
		i = 0;
		while (link != (*stack_b)->next)
		{
			if (link)
				link = link->previous;
			else
				link = *stack_b;
			printf("stack b pos %i: %i\n", i, link->content);
			i++;
		}
		freestack(stack_a);
		freestack(stack_b);
	}
	else
		return (0);
	return (0);
}
