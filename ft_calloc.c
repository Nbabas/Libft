/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:48:26 by nbascaul          #+#    #+#             */
/*   Updated: 2020/10/22 20:41:21 by nbascaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Return pointer to memory zone allocated for n members of size each.
*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;

	tmp = malloc(size * count);
    if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, size * count);
	return (tmp);
}