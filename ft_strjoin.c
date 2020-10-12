/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:47:47 by nbascaul          #+#    #+#             */
/*   Updated: 2020/10/12 16:26:45 by nbascaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *newstr;

    if (!s1 && !s2)
        return (NULL);
    else if (!s1)
        return (ft_strdup(s2));
    else if (!s2)
        return (ft_strdup(s1));
    newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (newstr == NULL)
        return (NULL);
    ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
    ft_strlcat(newstr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
    return (newstr);
}