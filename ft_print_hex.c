/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnihei <rnihei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:37:20 by rnihei            #+#    #+#             */
/*   Updated: 2025/07/22 16:37:23 by rnihei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	ft_print_hex_digit(unsigned int num, const char format)
{
	if (num <= 9)
	{
		if (ft_print_char(num + '0') == -1)
			return (-1);
	}
	else
	{
		if (format == 'x')
		{
			if (ft_print_char(num - 10 + 'a') == -1)
				return (-1);
		}
		if (format == 'X')
		{
			if (ft_print_char(num - 10 + 'A') == -1)
				return (-1);
		}
	}
	return (0);
}

static int	ft_put_hex(unsigned int num, const char format)
{
	int	ret;

	if (num >= 16)
	{
		ret = ft_put_hex(num / 16, format);
		if (ret == -1)
			return (-1);
		ret = ft_put_hex(num % 16, format);
		if (ret == -1)
			return (-1);
	}
	else
		return (ft_print_hex_digit(num, format));
	return (0);
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (ft_put_hex(num, format) == -1)
			return (-1);
	}
	return (ft_hex_len(num));
}
