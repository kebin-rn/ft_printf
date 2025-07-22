/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnihei <rnihei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:32:26 by rnihei            #+#    #+#             */
/*   Updated: 2025/07/22 19:12:03 by rnihei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_char_types(va_list args, const char format)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret = ft_print_char(va_arg(args, int));
	else if (format == 's')
		ret = ft_print_str(va_arg(args, char *));
	else if (format == '%')
		ret = ft_print_percent();
	return (ret);
}

static int	ft_format_num_types(va_list args, const char format)
{
	int	ret;

	ret = 0;
	if (format == 'd' || format == 'i')
		ret = ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		ret = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		ret = ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		ret = ft_print_ptr(va_arg(args, unsigned long long));
	return (ret);
}

static int	ft_format(va_list args, const char format)
{
	int	ret;

	if (format == 'c' || format == 's' || format == '%')
		ret = ft_format_char_types(args, format);
	else
		ret = ft_format_num_types(args, format);
	return (ret);
}

static int	ft_process_char(const char *str, int i, va_list args, int *len)
{
	int	ret;

	if (str[i] == '%')
	{
		ret = ft_format(args, str[i + 1]);
		if (ret == -1)
			return (-1);
		*len += ret;
		return (1);
	}
	else
	{
		ret = ft_print_char(str[i]);
		if (ret == -1)
			return (-1);
		*len += ret;
		return (0);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;
	int		skip;

	i = 0;
	print_length = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		skip = ft_process_char(str, i, args, &print_length);
		if (skip == -1)
		{
			va_end(args);
			return (-1);
		}
		i += skip + 1;
	}
	va_end(args);
	return (print_length);
}
