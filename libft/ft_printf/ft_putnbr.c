/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:33:44 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/19 14:40:48 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long int	i;
	int			count;

	i = nb;
	count = 0;
	if (i < 0)
	{
		count += ft_putchar('-');
		i = -i;
	}
	if (i >= 10)
	{
		count += ft_putnbr(i / 10);
	}
	count += ft_putchar((i % 10) + '0');
	return (count);
}
