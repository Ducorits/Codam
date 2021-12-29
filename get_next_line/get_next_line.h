#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

typedef struct	s_buf {
	int		size;
	char	*content;
}	t_buf;
char	*get_next_line(int fd);
int		check_newline(t_buf *buf);
char	*past_newline(t_buf *buf, int newline_index);
char	*str_join(t_buf *return_buf, t_buf *read_buf);
char	*until_newline(t_buf *buf, int newline_index);

#endif
