/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:02:00 by nbascaul          #+#    #+#             */
/*   Updated: 2020/10/12 16:22:22 by nbascaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_isincharset(const char *set, char c)
{
    while (*set)
    {
        if (*set == c)
            return (1);
        set++;
    }
    return (0);
}

static int  ft_getlen(const char *s1, const char *set)
{
    unsigned int    i;
    unsigned int    j;

    i = 0;
    while (ft_isincharset(set, s1[i]))
        i++;
    j = ft_strlen(s1) - 1;
    while (ft_isincharset(set, s1[j]) && j > 0)
        j--;
    return (j - i + 1);
}

char *ft_strtrim(char const *s1, char const *set)
{
    unsigned int    len;
    unsigned int    i;
    char            *newstr;

    if ((len = ft_getlen(s1, set)) <= 0)
        len = 0;
    newstr = (char *)malloc(sizeof(char) * (len + 1));
    if (newstr == NULL)
        return (NULL);
    while (ft_isincharset(set, *s1))
        s1++;
    i = 0;
    while (len > 0)
    {
        newstr[i] = s1[i];
        i++;
        len--;
    }
    newstr[i] = '\0';
    return (newstr);
}