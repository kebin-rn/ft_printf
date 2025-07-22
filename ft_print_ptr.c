/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnihei <rnihei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:38:31 by rnihei            #+#    #+#             */
/*   Updated: 2025/07/22 16:38:33 by rnihei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	ft_put_ptr(unsigned long long num)
{
	int	ret;

	if (num >= 16)
	{
		ret = ft_put_ptr(num / 16);
		if (ret == -1)
			return (-1);
		ret = ft_put_ptr(num % 16);
		if (ret == -1)
			return (-1);
	}
	else
	{
		if (num <= 9)
		{
			if (ft_print_char(num + '0') == -1)
				return (-1);
		}
		else
		{
			if (ft_print_char(num - 10 + 'a') == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;
	int	ret;

	print_length = 0;
	if (ptr == 0)
	{
		ret = write(1, "(nil)", 5);
		if (ret == -1)
			return (-1);
		print_length += ret;
	}
	else
	{
		ret = write(1, "0x", 2);
		if (ret == -1)
			return (-1);
		print_length += ret;
		if (ft_put_ptr(ptr) == -1)
			return (-1);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
