/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:59:18 by jcapistr          #+#    #+#             */
/*   Updated: 2022/11/21 21:59:18 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	if (str == NULL)
		return (NULL);
	if (chr == '\0')
		return ((char *)(str + ft_strlen(str)));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
