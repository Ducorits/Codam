/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:22 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/11 20:28:41 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	if (argc > 1)
	{
		stack_a = init_stack();
		fill_stack(stack_a, argv);
		if (stack_a == 0)
		{
			write(1, "Error", 5);
			return (0);
		}
		i = 0;
		while (i < argc -1)
		{
			ft_printf("%p\n", stack_a->top);
			i++;
		}
	}
	else
		return (0);
	return (0);
}
