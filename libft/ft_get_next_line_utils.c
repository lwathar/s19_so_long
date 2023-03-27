/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:25:19 by lowathar          #+#    #+#             */
/*   Updated: 2023/03/14 14:28:52 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (str);
	return (0);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t i;
	
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin_gnl(char *lstr, char *buf)
{
	int i;
	int j;
	char *str;
	int sizetot;
	
	i = 0;
	j = 0;
	if (!lstr)
	{
		lstr = malloc(1);
		if(!lstr)
			return (NULL);
		lstr[0] = '\0';
	}
	sizetot = ft_strlen_gnl(lstr) + ft_strlen_gnl(buf);
	str = malloc(sizeof(char) * (sizetot + 1));
	if (!str)
		return (NULL); // check for ft_free
	while (lstr[i] != '\0')
	{
		str[i] = lstr[i];
		i++;
	}
	while(buf[j] != '\0')
	{
		str[i] = buf[j];
		i++;
		j++;
	}
	str[sizetot] = '\0';
	free (lstr);
	return (str);
}
