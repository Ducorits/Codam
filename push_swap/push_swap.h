/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/14 19:51:32 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_link	t_link;
struct	s_link
{
	struct s_link	*previous;
	int				content;
	struct s_link	*next;
};

// Stack utility functions
t_link	**make_empty_stack(void);
t_link	**make_stack(char **argv);
void	add_to_top(t_link **stack, t_link *new);
void	add_to_bottom(t_link **stack, t_link *new);
// Input error checking
int		input_error_check(int argc, char **argv);
// Rotate functions
void	rotate(t_link **stack);
void	rotate_both(t_link **stack_1, t_link **stack_2);
void	rev_rotate(t_link **stack);
void	rev_rotate_both(t_link **stack_1, t_link **stack_2);
// Push functions


// Swap functions
void	swap(t_link **stack);
void	swap_both(t_link **stack_1, t_link **stack_2);

#endif //PUSH_SWAP_H