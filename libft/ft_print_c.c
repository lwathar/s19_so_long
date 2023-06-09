/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:54 by lowathar          #+#    #+#             */
/*   Updated: 2023/02/21 14:00:08 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_c(t_struct *tab, va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar(c, tab);
}
