/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:02:51 by nbascaul          #+#    #+#             */
/*   Updated: 2020/11/23 10:06:56 by nbascaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Return an allocated (malloc) array. char c is the seperator.
**  Array is null-byte terminated.
*/

static size_t	word_count(char const *s, char c)
{
	size_t		wc;

	wc = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s)
				wc++;
		}
		s++;
	}
	return (wc);
}

static size_t	ft_w_len(char const *s, char c)
{
	int			len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char			**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char		**tstrs;
	size_t		wc;
	size_t		len;
	int			i;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	tstrs = (char **)malloc(sizeof(char*) * (wc + 1));
	if (!tstrs)
		return (NULL);
	i = 0;
	while (wc--)
	{
		while (*s && *s == c)
			s++;
		len = ft_w_len(s, c);
		if (!(tstrs[i] = (char*)malloc(sizeof(char) * len + 1)))
			return ft_malloc_error(tstrs);
		ft_strlcpy(tstrs[i], s, len + 1);
		s = s + len;
		i++;
	}
	tstrs[i] = NULL;
	return (tstrs);
}
