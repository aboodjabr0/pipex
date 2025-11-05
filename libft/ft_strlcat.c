/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:39:28 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/14 15:00:32 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t	size)
{
	size_t				i;
	size_t				s;
	size_t				d;
	size_t				sum;

	d = ft_strlen(dest);
	s = ft_strlen(src);
	i = 0;
	sum = 0;
	if (size > d)
	{
		sum = d + s;
	}
	else
	{
		sum = size + s;
	}
	while (src[i] != '\0' && size > (d + 1))
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = '\0';
	return (sum);
}

// int main ()
// {
// 	char dest[] = "rrrrrrrrrrrrrrr";

// 	printf("%d\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	printf("%s\n", dest);
// 	printf("%zu\n", ft_strlen(dest));
// }
