/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:23:16 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/14 15:03:13 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	return (NULL);
}
// int main()
// {
//     char s[] = "Hello";
//     char c = 'H';

//     char *a = ft_strrchr(s, c);

//         printf("%s", a);
// }