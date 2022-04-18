/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 14:01:44 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/18 20:27:03 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	while (*argv)
	{
		ft_printf("%s\n", *argv);
		argv++;
	}
	argc = argc;
	return (0);
}

		// i = 0;
		// link = 0;
		// while (link != (*stack_a)->next)
		// {
		// 	if (link)
		// 		link = link->previous;
		// 	else
		// 		link = *stack_a;
		// 	ft_printf("stack a pos %i: %i\n", i, link->content);
		// 	i++;
		// }
		// link = 0;
		// i = 0;
		// while (link != (*stack_b)->next)
		// {
		// 	if (link)
		// 		link = link->previous;
		// 	else
		// 		link = *stack_b;
		// 	ft_printf("stack b pos %i: %i\n", i, link->content);
		// 	i++;
		// }