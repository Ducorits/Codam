/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 13:12:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/24 14:02:52 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	*nums;

	i = 0;
	nums = malloc(sizeof(int) * (argc - 1));
	while (argv[i])
	{
		nums[i] = ft_atoi(argv[i]);
		j = 0;
		while (j < i)
		{
			if (nums[j] == nums[i])
			{
				free(nums);
				return (1);
			}
			else
				j++;
		}
		i++;
	}
	free(nums);
	return (0);
}

static int	check_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (j == 1 && argv[i][j] == 0)
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_error_check(int argc, char **argv)
{
	if (check_digits(argv) || check_duplicates(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
