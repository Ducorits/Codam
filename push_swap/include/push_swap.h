/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/15 21:10:46 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUBSIZE 1

typedef struct s_link	t_link;
struct	s_link
{
	struct s_link	*previous;
	int				content;
	unsigned int	index;
	struct s_link	*next;
};

// Stack utility functions
t_link	**make_empty_stack(void);
void	fill_stack(char **argv, t_link **stack);
int		freestack(t_link **stack);
void	add_to_top(t_link **stack, t_link *new);
void	add_to_bottom(t_link **stack, t_link *new);

// Sort utility functions
int		get_average_index(t_link **stack, int size);
void	push_to_b(t_link **stack_a, t_link **stack_b, int amount);
void	push_to_a(t_link **stack_a, t_link **stack_b, int amount);
void	reverse_b(t_link **stack_b, int amount);
void	reverse_a(t_link **stack_a, int amount);

// Input error checking
int		input_error_check(int argc, char **argv);

// Rotate functions
void	ra(t_link **stack_a);
void	rb(t_link **stack_b);
void	rr(t_link **stack_a, t_link **stack_b);
void	rra(t_link **stack_a);
void	rrb(t_link **stack_b);
void	rrr(t_link **stack_a, t_link **stack_b);

// Push functions
void	push(t_link **stack_1, t_link **stack_2);
void	pa(t_link **stack_a, t_link **stack_b);
void	pb(t_link **stack_a, t_link **stack_b);

// Swap functions
void	sa(t_link **stack_a);
void	sb(t_link **stack_b);
void	ss(t_link **tack_a, t_link **stack_b);

// Sort functions
void	bubble_sort(t_link **stack_a, int argc);
void	radix_sort(t_link **stack_a, t_link **stack_b, int argc);
void	quick_sort(t_link **stack_a, t_link **stack_b, int size);
void	quick_sort2(t_link **stack_a, t_link **stack_b, int size);
void	sort_indexes(t_link **copy_a, t_link **copy_b, int argc);
int		sort(t_link **stack_a, t_link **stack_b, int argc);
void	update_indexes(t_link **stack_a, t_link **copy_a, int size);

// Quick sort funtions
void	filter_a(t_link **stack_a, t_link **stack_b, int size);
void	filter_b(t_link **stack_a, t_link **stack_b, int size);
void	recurb(t_link **stack_a, t_link **stack_b, int size);
void	recura(t_link **stack_a, t_link **stack_b, int size);

// Testing functions (remove before publish)
int		check_sorted(t_link **stack, int size);
void	print_stacks(t_link **stack_a, t_link **stack_b);
void	print_stack(t_link **stack);

#endif //PUSH_SWAP_H