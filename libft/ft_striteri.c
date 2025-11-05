/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:33:12 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/10 15:22:18 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <ctype.h>

// void    f(unsigned int i, char *str)
// {
// 	// str[i] = 'a';
// 	*str = 'a';
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (*s == '\0')
	{
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// int main()
// {
// 	char str[] = "12345";

//     printf("str :%s\n", str);
//     ft_striteri(str, f);
//     printf("str : %s\n", str);
// }
