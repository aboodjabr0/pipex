/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:58:42 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/14 19:10:25 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

void	ft_free_2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	**split_words(char **str, const char *s, char c, int size)
{
	int			i;
	const char	*start;

	s = (char *)s;
	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		str[i] = ft_substr(start, 0, s - start);
		if (!str[i])
		{
			ft_free_2d(str);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_str;
	int		count_word;

	count_word = word_count(s, c);
	splited_str = malloc((count_word + 1) * sizeof(char *));
	if (!splited_str)
		return (NULL);
	return (split_words(splited_str, s, c, count_word));
}

// int	main(void)
// {
// 	char *str = ",,,,,   messi , is , the , best ,
// player ,, in ,,, the ,,,world, hansi flick 3mk";
//		world, hansi flick 3mk";
// 	char	**s;
// 	s = ft_split(str, ',');
// 	for(int i = 0; s[i]; i++)
// 		printf("%s\n", s[i]);
// 	ft_free_2d(s);
// 	return (0);
// }