/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:22 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/07 21:02:20 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_link	*stack_a;
	// t_link	*stack_b;

	if (argc > 1)
	{
		stack_a = make_stack(argc, argv);
		if (stack_a == 0)
		{
			write(1, "Error", 5);
			return (0);
		}
	}
	else
		return (0);
}
