/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: dritsema <dritsema@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2021/12/31 14:09:41 by dritsema       #+#    #+#                */
/*   Updated: 2021/12/31 14:52:27 by dritsema        ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_buf
{
	int		size;
	char	*content;
}	t_buf;

char	*get_next_line(int fd);
int		newline_pos(t_buf read);
int		check_newline(t_buf *buf, t_buf r_buf);
char	*past_newline(t_buf *buf);
char	*add_to_str(t_buf read, t_buf *buf);

#endif
