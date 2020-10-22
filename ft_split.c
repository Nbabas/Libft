/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:02:51 by nbascaul          #+#    #+#             */
/*   Updated: 2020/10/13 17:19:26 by nbascaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t   word_count(char const *s, char c)
{
    size_t  wc;

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

static size_t   ft_w_len(char const *s, char c)
{
	int     len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char            **ft_split(char const *s, char c)
{
    char    **tstrs;
    size_t  wc;
    size_t  len;
    int     i;
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
        tstrs[i] = ft_substr(s, 0, len);
        s = s + len;
        i++;
    }
    tstrs[i] = NULL;
    return (tstrs);
}