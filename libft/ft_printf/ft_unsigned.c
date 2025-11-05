/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:14:33 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/19 14:40:54 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int nb)
{
	int		i;
	int		count;
	char	c[10];

	i = 0;
	count = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		c[i++] = nb % 10 + '0';
		nb /= 10;
	}
	while (i-- > 0)
		count += ft_putchar(c[i]);
	return (count);
}
