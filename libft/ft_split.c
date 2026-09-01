/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:41:06 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 13:45:05 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			count++;
		}
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
	}
	return (count);
}

static char	**ft_free_memory(char **array, int words)
{
	while (words > 0)
	{
		free(array[words]);
		words--;
	}
	free(array);
	return (NULL);
}

static void	ft_wd(char **str, int *w, char c)
{
	int	i;

	*str += *w;
	*w = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*w)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*str;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	str = (char *)s;
	words = 0;
	while (i < ft_count_words(s, c))
	{
		ft_wd(&str, &words, c);
		result[i] = (char *)malloc(sizeof(char) * (words + 1));
		if (!(result[i]))
			return (ft_free_memory(result, i - 1));
		ft_strlcpy(result[i], str, words + 1);
		i++;
	}
	result[i] = NULL;
	return (result);
}
/*int main()
{
	char **array;
	array = ft_split("aaubbbbbucccudddueeeeeeeeeeufffffuhhhhh", 'u');
	int i;
	i = 0;
	while(array[i] != 0)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}*/
