/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:22 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/24 17:54:57 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		sort_indexes(&stack_copy_a, &stack_copy_b, argc - 1);
		update_indexes(&stack_a, &stack_copy_a, argc - 1);
		if (argc - 1 > 5)
			hybrid_sort(&stack_a, &stack_b, argc - 1);
		else
			small_sort(&stack_a, &stack_b, argc - 1);
		freestack(&stack_copy_a);
		freestack(&stack_a);
	}
	else
		return (0);
	return (0);
}
