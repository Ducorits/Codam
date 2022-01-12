/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/31 14:09:41 by dritsema      #+#    #+#                 */
/*   Updated: 2022/01/12 12:41:32 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_buf
{
	int		size;
	char	content[BUFFER_SIZE];
}	t_buf;
typedef struct s_return
{
	int		size;
	char	*content;
}	t_return;

char	*get_next_line(int fd);
int		newline_pos(t_buf read);
int		check_newline(t_return *buf);
void	past_newline(t_buf *buf);
char	*add_to_str(t_buf read, t_return *buf);

#endif
