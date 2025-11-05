/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:45:32 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/21 21:51:32 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	i;
	long	sign;
	long	sum;

	i = 0;
	sign = 1;
	sum = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = sum * 10 + (nptr[i] - '0');
		i++;
	}
	return (sum * sign);
}
/*int main()
{
	char a[] = "2147483647";
	char b[] = "-5:7";
	char c[] = "  -12dfg235";
	char d[] = "  -a12235";
	char f[] = "  	+12235";
	printf("%d\n%d\n%d\n%d\n%d", 
	ft_atoi(a), ft_atoi(b), 
	ft_atoi(c), ft_atoi(d), ft_atoi(f));
}*/