/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:41:50 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/07 20:50:12 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
	{
		return (1);
	}
	return (0);
}

/*int main()
{
	printf("%d",ft_isalnum('A'));
	printf("\n");
	printf("%d", ft_isalnum(1));
	printf("\n");
	printf("%d", ft_isalnum('%'));
	printf("\n");
}*/
