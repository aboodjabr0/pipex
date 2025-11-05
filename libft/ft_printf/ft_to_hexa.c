/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:14:25 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 18:03:36 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_to_hexa(unsigned int nb, char format)
{
	char	*str;
	int		count;

	if (format == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb >= 16)
	{
		count += ft_to_hexa(nb / 16, format);
		count += ft_putchar(str[nb % 16]);
	}
	else
		count += ft_putchar(str[nb]);
	return (count);
}
