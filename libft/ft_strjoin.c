/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:35:32 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/11 13:44:09 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len1;
	size_t	len2;
	char	*new_string;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	new_string = malloc(sizeof(char) * len1 + len2 + 1);
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_string[i++] = s2[j];
		j++;
	}
	new_string[i] = '\0';
	return (new_string);
}
/*int main()
{
	char s1[] = "Hello ";
	char s2[] = "World";

	char *a = ft_strjoin(s1, s2);
	printf("%s", a);
}*/