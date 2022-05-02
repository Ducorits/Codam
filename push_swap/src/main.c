/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:22 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/02 17:35:33 by dritsema      ########   odam.nl         */
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

	if (argc > 1 && !input_error_check(argc, &argv[1]))
	{
		stack_a = make_stack(argv);
		stack_b = make_empty_stack();
		sort(stack_a, stack_b, argc);
		print_stacks(stack_a, stack_b);
		freestack(stack_a);
		freestack(stack_b);
	}
	else
		return (0);
	return (0);
}
