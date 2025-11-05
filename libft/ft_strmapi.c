/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:06:44 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/11 12:31:07 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*modified_str;

	modified_str = malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (!modified_str)
		return (NULL);
	while (i < ft_strlen(s))
	{
		modified_str[i] = (*f)(i, s[i]);
		i++;
	}
	modified_str[i] = '\0';
	return (modified_str);
}
