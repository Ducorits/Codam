/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:22 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/18 15:57:04 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_link	*stack_a;
	t_link	*stack_b;
	t_link	*stack_copy_a;
	t_link	*stack_copy_b;

	if (argc > 1 && !input_error_check(argc, &argv[1]))
	{
		stack_a = 0;
		stack_b = 0;
		stack_copy_a = 0;
		stack_copy_b = 0;
		fill_stack(argv, &stack_copy_a);
		fill_stack(argv, &stack_a);
		ft_printf("Sort based on indexes\n");
		sort_indexes(&stack_copy_a, &stack_copy_b, argc - 1);
		ft_printf("Update indexes\n");
		update_indexes(&stack_a, &stack_copy_a, argc - 1);
		ft_printf("Quick sort\n");
		my_sort(&stack_a, &stack_b, argc - 1);
		// quick_sort(&stack_a, &stack_b, argc - 1);
		// radix_sort(&stack_a, &stack_b, argc);
		// print_stacks(&stack_a, &stack_b);
		freestack(&stack_copy_a);
		freestack(&stack_copy_b);
		freestack(&stack_a);
		freestack(&stack_b);
	}
	else
		return (0);
	return (0);
}
