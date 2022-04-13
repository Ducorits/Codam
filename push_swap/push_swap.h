/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/13 19:52:19 by dritsema      ########   odam.nl         */
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
struct s_stack
{
	t_link	*top;
	t_link	*bottom;
};

t_link	*init_stack(void);
void	fill_stack(t_link **stack, char **argv);
t_link	*make_stack(int argc, char **argv);
void	add_to_bottom(t_link **stack, t_link *new);

#endif //PUSH_SWAP_H