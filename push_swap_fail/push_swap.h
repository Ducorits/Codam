/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/04 17:05:19 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_link	t_link;
typedef struct s_stack	t_stack;
struct	s_link
{
	struct s_link	*previous;
	int				content;
	struct s_link	*next;
};
struct	s_stack
{
	struct s_link	*top;
	struct s_link	*bottom;
};

// // Stack utility functions
// t_link	**make_empty_stack(void);
// t_link	**make_stack(char **argv);
// int		freestack(t_link **stack);
// void	add_to_top(t_link **stack, t_link *new);
// void	add_to_bottom(t_link **stack, t_link *new);

// // Input error checking
// int		input_error_check(int argc, char **argv);

// // Rotate functions
// void	ra(t_link **stack_a);
// void	rb(t_link **stack_b);
// void	rr(t_link **stack_a, t_link **stack_b);
// void	rra(t_link **stack_a);
// void	rrb(t_link **stack_b);
// void	rrr(t_link **stack_a, t_link **stack_b);

// // Push functions
// void	pa(t_link **stack_a, t_link **stack_b);
// void	pb(t_link **stack_a, t_link **stack_b);

// // Swap functions
// void	sa(t_link **stack_a);
// void	sb(t_link **stack_b);
// void	ss(t_link **tack_a, t_link **stack_b);

// // Sort functions
// void	bubble_sort(t_link **stack_a, int argc);
// int		sort(t_link **stack_a, t_link **stack_b, int argc);

// // Testing functions (remove before publish)
// int		check_sorted(t_link **stack, int size);
// void	print_stacks(t_link **stack_a, t_link **stack_b);
// void	print_stack(t_link **stack);

// Stack utility functions
// t_link	**make_empty_stack(void);
void	fill_stack(char **argv, t_stack *stack);
int		freestack(t_stack *stack);
void	add_to_top(t_stack *stack, t_link *new);
void	add_to_bottom(t_stack *stack, t_link *new);

// Input error checking
int		input_error_check(int argc, char **argv);

// Rotate functions
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Push functions
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

// Swap functions
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

// Sort functions
void	bubble_sort(t_stack *stack_a, int argc);
int		sort(t_stack *stack_a, t_stack *stack_b, int argc);

// Testing functions (remove before publish)
int		check_sorted(t_stack *stack, int size);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_stack(t_stack *stack);

#endif //PUSH_SWAP_H