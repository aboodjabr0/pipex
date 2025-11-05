/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:56:56 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/19 18:18:45 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_specifier(va_list	args, char c, int *count)
{
	unsigned long	p;

	if (c == 'c')
		(*count) += ft_putchar(va_arg(args, int));
	else if (c == 's')
		(*count) += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long);
		if (p == 0)
			(*count) += ft_putstr("(nil)");
		else
		{
			(*count) += ft_putstr("0x");
			(*count) += ft_pointer(p);
		}
	}
	else if (c == 'd' || c == 'i')
		(*count) += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		(*count) += ft_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		(*count) += ft_to_hexa(va_arg(args, unsigned long), c);
	else if (c == '%')
		(*count) += ft_putchar('%');
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!input)
		return (-1);
	va_start(args, input);
	count = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '%')
			count += (int)write(1, &input[i], 1);
		else
		{
			i++;
			if (!input[i])
				break ;
			check_specifier(args, input[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int a = 42;
// 	void *ptr = &a;

//     int c1;
//     int c2;

//     c1 = printf("%c\n", 'c');
//     c2 = ft_printf("%c\n", 'c');

//     printf("printf returned: %d\n", c1);
//     printf("ft_printf returned: %d\n", c2);
// 	printf("\n--------------------------------\n");

// 	int s1;
// 	int s2;

// 	s1 = printf("%s\n", "hello, world");
// 	c2 = ft_printf ("%s\n", "hello, world");

// 	printf("printf returned: %d\n", s1);
//     printf("ft_printf returned: %d\n", s2);
// 	printf("\n--------------------------------\n");

// 	int p1;
// 	int p2;

// 	p1 = printf("%p\n", ptr);
// 	p2 = ft_printf ("%p\n", ptr);

// 	printf("printf returned: %d\n", p1);
//     printf("ft_printf returned: %d\n", p2);
// 	printf("\n--------------------------------\n");

// 	int d_i_1;
// 	int d_i_2;

// 	d_i_1 = printf("%d\n%i\n", 12345, 12345);
// 	d_i_2 = ft_printf ("%d\n%i\n", 12345, 12345);

// 	printf("printf returned: %d\n", d_i_1);
//     printf("ft_printf returned: %d\n", d_i_2);
// 	printf("\n--------------------------------\n");

// 	int u1;
// 	int u2;

// 	u1 = printf("%u\n", 5482);
// 	u2 = ft_printf ("%u\n", 5482);

// 	printf("printf returned: %d\n", u1);
//     printf("ft_printf returned: %d\n", u2);
// 	printf("\n--------------------------------\n");

// 	int x1;
// 	int x2;

// 	x1 = printf("%x", 101);
// 	x2 = ft_printf("%x, 101");

// 	printf("printf returned: %d\n", x1);
//     printf("ft_printf returned: %d\n", x2);
// 	printf("\n--------------------------------\n");
// }
