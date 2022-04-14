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

int	main(int argc, char **argv)
{
	t_link	**stack_a;
	t_link	**stack_b;
	t_link	*link;
	int		i;

	input_error_check(argc, &argv[1]);
	if (argc > 1)
	{
		stack_a = make_stack(argv);
		stack_b = make_empty_stack();
		
		i = 0;
		link = 0;
		while (i < argc -1)
		{
			if (link)
				link = link->next;
			else
				link = *stack_a;
			ft_printf("pos %i: %i\n", i, link->content);
			i++;
		}
	}
	else
		return (0);
	return (0);
}
