/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_sort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 14:28:59 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/23 22:27:35 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

/*	Filter everything lower than the average.
	everything that matches the filter gets pushed to stack b. */
static int	filter_low(t_link **stack_a, t_link **stack_b, int size)
{
	int				i;
	int				count;
	unsigned int	average;

	i = 0;
	count = 0;
	average = get_average_index(stack_a, size);
	while (i < size)
	{
		if ((*stack_a)->index <= average)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
		i++;
	}
	return (count);
}

int	get_stack_size(t_link **stack)
{
	t_link	*tmp;
	int		size;

	size = 0;
	if (*stack)
	{
		tmp = *stack;
		while (tmp)
		{
			tmp = tmp->next;
			size++;
			if (tmp == *stack)
				tmp = 0;
		}
	}
	return (size);
}

int	move_count_a(t_link **stack_a, t_link *link, unsigned int size)
{
	t_link			*tmp;
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	if (*stack_a)
	{
		tmp = *stack_a;
		while (i < size)
		{
			if ((link->index > tmp->previous->index && link->index < tmp->index)
				|| (link->index == 0 && tmp->index < tmp->previous->index)
				|| (link->index == size - 1 && tmp->index > tmp->next->index))
				break ;
			count++;
			tmp = tmp->next;
			i++;
		}
		if (count > size / 2)
			count = (size - count) * -1;
	}
	return (count);
}

void	calc_moves(t_link *link)
{
	int	rot_a;
	int	rot_b;

	link->moves = 0;
	rot_a = link->rotate_a;
	rot_b = link->rotate_b;
	while (rot_a > 0 || rot_b > 0)
	{
		if (rot_a > 0)
			rot_a--;
		if (rot_b > 0)
			rot_b--;
		link->moves++;
	}
	while (rot_a < 0 || rot_b < 0)
	{
		if (rot_a < 0)
			rot_a++;
		if (rot_b < 0)
			rot_b++;
		link->moves++;
	}
}

void	update_move_count(t_link **stack_a, t_link **stack_b)
{
	int		size_a;
	int		size_b;
	int		move_a;
	int		move_b;
	t_link	*tmp;

	tmp = *stack_b;
	move_b = 0;
	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	while (tmp)
	{
		move_a = move_count_a(stack_a, tmp, size_a);
		tmp->rotate_a = move_a;
		if (move_b > size_b / 2)
			tmp->rotate_b = (size_b - move_b) * -1;
		else
			tmp->rotate_b = move_b;
		calc_moves(tmp);
		move_b++;
		tmp = tmp->next;
		if (tmp == *stack_b)
			tmp = 0;
	}
}

void	do_optimized_moves(t_link **stack_a, t_link **stack_b, t_link *to_move)
{
	// ft_printf("to_move - %p\n", to_move);
	while (to_move->rotate_a > 0 && to_move->rotate_b > 0)
	{
		rr(stack_a, stack_b);
		to_move->rotate_a--;
		to_move->rotate_b--;
	}
	while (to_move->rotate_a < 0 && to_move->rotate_b < 0)
	{
		// ft_printf("rot_a %i, rot_b %i\n", to_move->rotate_a, to_move->rotate_b);
		rrr(stack_a, stack_b);
		to_move->rotate_a++;
		to_move->rotate_b++;
	}
}

void	do_moves(t_link **stack_a, t_link **stack_b, t_link *to_move)
{
	while (to_move->rotate_a != 0 || to_move->rotate_b != 0)
	{
		if (to_move->rotate_a > 0)
		{
			ra(stack_a);
			to_move->rotate_a--;
		}
		else if (to_move->rotate_a < 0)
		{
			rra(stack_a);
			to_move->rotate_a++;
		}
		if (to_move->rotate_b > 0)
		{
			rb(stack_b);
			to_move->rotate_b--;
		}
		else if (to_move->rotate_b < 0)
		{
			rrb(stack_b);
			to_move->rotate_b++;
		}
	}
}

void	do_best_moves(t_link **stack_a, t_link **stack_b)
{
	t_link	*tmp;
	t_link	*to_move;
	int		least_moves;

	if (*stack_b)
	{
		tmp = *stack_b;
		least_moves = tmp->moves;
		to_move = tmp;
		while (tmp)
		{
			if (tmp->moves < least_moves)
			{
				least_moves = tmp->moves;
				to_move = tmp;
			}
			tmp = tmp->next;
			if (tmp == *stack_b)
				tmp = 0;
		}
		if (to_move)
		{
			do_optimized_moves(stack_a, stack_b, to_move);
			do_moves(stack_a, stack_b, to_move);
		}
	}
}


void	print_move(t_link **stack_b)
{
	t_link	*tmp;

	tmp = *stack_b;
	ft_printf("stack_b move info:\n");
	while (tmp)
	{
		ft_printf("- val: %i	Index %i	: rotate_a: %i, rotate_b: %i, moves: %i\n", tmp->content, tmp->index, tmp->rotate_a, tmp->rotate_b, tmp->moves);
		tmp = tmp->next;
		if (tmp == *stack_b)
			tmp = 0;
	}
}

/*	Move all indexes that are above the average index from stack a to stack b.
	Update average index and repeat untill stack a is a size we can easily sort.
	Sort stack a and move everything back in chunks. */
void	my_sort(t_link **stack_a, t_link **stack_b, int size)
{
	int	filter_size;

	filter_size = size;
	while (*stack_a)
	{
		filter_size -= filter_low(stack_a, stack_b, filter_size);
	}
	while (*stack_b)
	{
		// ft_printf("my_sort while\n");
		// ft_printf("count_moves\n");
		update_move_count(stack_a, stack_b);
		print_move(stack_b);
		ft_printf("Stack_a:\n");
		print_stack(stack_a);
		// ft_printf("to move %i\n", to_move);
		// ft_printf("do_best_moves\n");
		do_best_moves(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
