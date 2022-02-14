/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:22:51 by baubigna          #+#    #+#             */
/*   Updated: 2022/02/09 08:23:19 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	treat_str(char *s)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		return (i);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

int	nb_len(int n)
{
	int	l;

	l = 0;
	if (n < 0)
	{
		l++;
		n = -n;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		l++;
	}
	l++;
	return (l);
}

int	treat_int(int n)
{
	int	printeda;

	printeda = nb_len(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			treat_char(45);
			n *= -1;
		}
		if (n > 9)
			treat_int(n / 10);
		treat_char(n % 10 + 48);
	}
	return (printeda);
}

int	treat_ptr(unsigned long l)
{
	int			printedd;
	char		*base;

	printedd = 0;
	base = "0123456789abcdef";
	if (l < 16)
		printedd += treat_char(base[l % 16]);
	else
	{
		printedd += treat_ptr(l / 16);
		printedd += treat_ptr(l % 16);
	}
	return (printedd);
}

int	treat_args(va_list args, const char c)
{
	int	printed_char;

	if (c == 'c')
		printed_char = treat_char(va_arg(args, int));
	if (c == 's')
		printed_char = treat_str(va_arg(args, char *));
	if (c == 'p')
	{
		printed_char = treat_str("0x");
		printed_char += treat_ptr(va_arg(args, unsigned long));
	}
	if (c == 'd' || c == 'i')
		printed_char = treat_int(va_arg(args, int));
	if (c == 'u')
		printed_char = treat_unsint(va_arg(args, unsigned int));
	if (c == 'x')
		printed_char = treat_hexa(va_arg(args, unsigned int), 0);
	if (c == 'X')
		printed_char = treat_hexa(va_arg(args, unsigned int), 1);
	if (c == '%')
		printed_char = treat_char('%');
	return (printed_char);
}
