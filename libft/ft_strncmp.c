/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:12:23 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/14 15:06:00 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (0);
	}
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return (((unsigned char) s1[i] - (unsigned char) s2[i]));
		}
		i++;
	}
	return (0);
}

/*int main()
{
	char s1[] = "test\200";
	char s2[] = "test\0";

	int x = ft_strncmp(s1, s2, 6);
	printf("%d", x);
}*/
