/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:02:51 by nbascaul          #+#    #+#             */
/*   Updated: 2020/11/23 12:57:46 by nbascaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Return an allocated (malloc) array. char c is the seperator.
**  Array is null-byte terminated.
*/

static char		**ft_malloc_error(char **tab)
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

static size_t    ft_wordlen(char const *s, char c)
{
    size_t    len;

    len = 0;
    while (s[len] != c && s[len] != '\0')
        len++;
    return (len);
}

static int        ft_wordcount(char const *s, char c)
{
    int        nb_word;
    int        i;

    i = 0;
    nb_word = 0;
    if (s[i] != c && s[i])
        nb_word++;
    while (s[i])
    {
        while (s[i] == c)
        {
            i++;
            if (s[i] != c && s[i])
                nb_word++;
        }
        i++;
    }
    return (nb_word);
}

char            **ft_split(char const *s, char c)
{
    char    **tab;
    int        nb_word;
    size_t    wordlen;
    int        j;

    if (!s)
        return (0);
    nb_word = ft_wordcount(s, c);
    if (!(tab = (char **)malloc(sizeof(char *) * (nb_word + 1))))
        return (NULL);
    j = 0;
    while (nb_word--)
    {
        while (*s == c && *s)
            s++;
        wordlen = ft_wordlen(s, c);
		tab[j] = (char*)malloc(sizeof(char) * wordlen + 1);
		if (!tab[j])
			return (ft_malloc_error(tab));
        ft_strlcpy(tab[j], s, wordlen + 1);
        j++;
        s += wordlen;
    }
    tab[j] = NULL;
    return (tab);
}
