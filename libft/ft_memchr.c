/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:24:34 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/14 15:04:20 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*d;
	size_t				i;

	d = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
		{
			return ((void *)(d + i));
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
    unsigned char s[] = "HEllo";
    char c = 'o';
    size_t n = 3;

    unsigned char *a = ft_memchr(s, c, n);

    printf("%s", a);
}*/
