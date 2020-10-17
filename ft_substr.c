/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:26:52 by nbascaul          #+#    #+#             */
/*   Updated: 2020/10/12 15:45:27 by nbascaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *newstr;

    if (s == NULL)
        return (NULL);
    if (ft_strlen(s) < start)
        return (ft_strdup(""));
    newstr = (char *)malloc(sizeof(char) * (len + 1));
    if (newstr == NULL)
        return (NULL);
    ft_strlcpy(newstr, s + start, len + 1);
    return (newstr);
}
