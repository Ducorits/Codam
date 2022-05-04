/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 13:11:13 by dritsema      #+#    #+#                 */
/*   Updated: 2022/04/11 13:11:14 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// printf stuff?
int	ft_printf(const char *s, ...);
int	ft_printhex(unsigned long n);
int	ft_upprinthex(unsigned long n);
int	ft_printun(unsigned int n);
int	ft_printchar(char c);
int	ft_printnbr(int n);
int	ft_printstr(char *s);
#endif /* FT_PRINTF>H */
