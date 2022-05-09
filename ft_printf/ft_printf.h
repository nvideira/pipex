/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:13 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/13 22:27:06 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *s, ...);
int			check_type(char c);
size_t		next_arg(char c, int *char_print, va_list args);
int			ft_putnbr_fd(int n, int fd);
int			ft_putunsnbr_fd(unsigned int n, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putchar_fd(char c, int fd);
size_t		ft_strlen(const char *str);
long int	dec_hexa(unsigned long n, int fd, char *base);
void		ft_strcpy(char *src, char *dst);
int			do_thing(size_t index, char *string, int char_print, va_list args);
#endif