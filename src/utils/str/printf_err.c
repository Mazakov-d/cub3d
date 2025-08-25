/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:00:00 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/25 11:16:29 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	handle_string(char *buf, int pos, const char **fmt, va_list *args)
{
	char	*s;

	*fmt += 2;
	s = va_arg(*args, char *);
	if (!s)
		s = "(null)";
	while (*s && pos < 1023)
		buf[pos++] = *s++;
	return (pos);
}

static int	num_len(int num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	handle_int(char *buf, int pos, const char **fmt, va_list *args)
{
	int	num;
	int	i;
	int	len;

	*fmt += 2;
	num = va_arg(*args, int);
	len = num_len(num);
	if (len >= 1023 - pos)
		return (pos);
	if (num < 0)
	{
		num = -num;
		buf[pos++] = '-';
		len--;
	}
	i = 0;
	while (len)
	{
		buf[(pos++) + (len--) - (i++) - 1] = '0' + (num % 10);
		num /= 10;
	}
	return (pos);
}

static int	handle_char(char *buf, int pos, const char **fmt, va_list *args)
{
	int	c;

	*fmt += 2;
	c = va_arg(*args, int);
	if (pos < 1023)
		buf[pos++] = (char)c;
	return (pos);
}

/**
 * @returns always EXIT_FAILURE
 */
int	printf_err(const char *fmt, ...)
{
	char	buf[1024];
	int		pos;
	va_list	args;

	pos = 0;
	va_start(args, fmt);
	ft_memcpy(buf, "Error\n", 6);
	pos += 6;
	while (*fmt && pos < 1023)
	{
		if (*fmt == '%' && *(fmt + 1) == 'c')
			pos = handle_char(buf, pos, &fmt, &args);
		else if (*fmt == '%' && *(fmt + 1) == 's')
			pos = handle_string(buf, pos, &fmt, &args);
		else if (*fmt == '%' && *(fmt + 1) == 'd')
			pos = handle_int(buf, pos, &fmt, &args);
		else
			buf[pos++] = *fmt++;
	}
	va_end(args);
	buf[pos] = '\0';
	if (write(STDERR_FILENO, buf, pos) < 0)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}
