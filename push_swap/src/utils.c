/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:57 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/07 21:03:44 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>
#include "../libft/libft.h"

// int	cartoi(char *str)
// {
// 	int	num;
// 	int	min;

// 	while (*str)
// 	{
// 		if (*str >= '0' && *str <= '9')
// 		{
// 			num *= 10;
// 			num += *str - '0';
// 		}
// 		else if (*str == '-')
// 		{
// 			min = 1;
// 		}
// 		else if (*str == '+')
// 		{
// 			min = 0;
// 		}
// 		else
// 		{
// 			write(1, "Error\n", 6);
// 			return (0);
// 		}
// 	}
// 	if (min)
// 		num *= -1;
// 	return (num);
// }


t_link	*make_stack(int argc, char **argv)
{
	t_link	*link;
	int		num;
	int		i;

	i = 0;
	link = malloc(sizeof(t_link));
	while (i < argc)
	{
	num = ft_atoi(argv[i]);
	link->content = malloc(sizeof(int) * num);
	i++;
	}
	return (link);
}
