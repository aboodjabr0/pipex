/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:35:36 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/14 14:51:46 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*u;
	size_t				i;

	u = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		u[i] = (unsigned char)c;
		i++;
	}
	return (u);
}

/*int main()
{
	int	o[] = {0,0,0,0};
	//size_t n = 7;

	ft_memset(o,1,sizeof(o));

	for (int i = 0; i < 4; i++)
	{
		printf("%d", o[i]);
		printf("\n");
	}
}*/
