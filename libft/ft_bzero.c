/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:37:02 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/14 14:52:35 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char		*u;
	size_t				i;

	u = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		u[i] = '\0';
		i++;
	}
	return (u);
}

/*int main()
{
	char x[] = "Hello";
	size_t n = 3;
	int	i;
	i = n;
	char *y = ft_bzero(x, n);
	while(y[i])
	{
		printf("%c", y[i]);
		i++;
	}
}*/
