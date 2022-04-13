/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:22 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/13 19:51:49 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_link	*stack_a;
	t_link	*link;
	int		i;

	if (argc > 1)
	{
		stack_a = init_stack();
		fill_stack(&stack_a, argv);
		if (stack_a == 0)
		{
			write(1, "Error", 5);
			return (0);
		}
		i = 0;
		link = 0;
		while (i < argc -1)
		{
			if (link)
				link = link->next;
			else
				link = stack_a;
			ft_printf("%p Content: %i\n", link, link->content);
			i++;
		}
		ft_printf("%p Stack top content: %i\n",
			*stack_a, stack_a->content);
		ft_printf("%p Stack bottom content: %i\n",
			stack_a->previous, stack_a->previous->content);
	}
	else
		return (0);
	return (0);
}
