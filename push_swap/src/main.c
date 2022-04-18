/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:22 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/18 20:27:12 by dritsema      ########   odam.nl         */
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
		freestack(stack_a);
		freestack(stack_b);
	}
	else
		return (0);
	return (0);
}
