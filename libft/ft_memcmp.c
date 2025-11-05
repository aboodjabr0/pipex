/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:26:07 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/07 16:01:48 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*d1;
	unsigned const char	*d2;
	size_t				i;

	i = 0;
	d1 = (unsigned const char *)s1;
	d2 = (unsigned const char *)s2;
	while (i < n)
	{
		if (d1[i] != d2[i])
		{
			return (d1[i] - d2[i]);
		}
		i++;
	}
	return (0);
}

/*int main()
{
    unsigned char s1[] = "dddd";
    unsigned char s2[] = "dddd";
    size_t n = 4;

    int x = ft_memcmp(s1, s2, n);
    printf("%d", x);
}*/