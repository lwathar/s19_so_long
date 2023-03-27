/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:19:31 by lwathar           #+#    #+#             */
/*   Updated: 2022/10/13 14:02:24 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size > 4294967296 && count > 4294967296)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (size * count));
	if (ptr == 0)
		return (0);
	i = 0;
	ft_bzero(ptr, count * size);
	return (ptr);
}
