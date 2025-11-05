/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:20:41 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/19 18:18:15 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long p)
{
	char	*str;
	int		count;

	str = "0123456789abcdef";
	count = 0;
	if (p >= 16)
	{
		count += ft_pointer(p / 16);
		count += ft_putchar(str[p % 16]);
	}
	else
		count += ft_putchar(str[p]);
	return (count);
}
