/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:36:41 by nbascaul          #+#    #+#             */
/*   Updated: 2020/11/19 18:27:07 by nbascaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(unsigned int n, unsigned int base_len)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(unsigned int n, const char *base)
{
	unsigned int	len;
	unsigned int	base_len;
	char			*res;

	base_len = (unsigned int)ft_strlen((char *)base);
	len = get_len(n, base_len);
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (NULL);
	res[0] = '0';
	while (n != 0)
	{
		len--;
		res[len] = base[(n % base_len)];
		n = n / base_len;
	}
	return (res);
}
