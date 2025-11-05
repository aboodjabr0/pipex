/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:15:12 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/11 12:27:12 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <limits.h>

int	num_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = 1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = num_len(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	len--;
	while (n)
	{
		str[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (str);
}

// int main()
// {
//     printf("%s\n", ft_itoa(INT_MAX));
//     return (0);
// }
