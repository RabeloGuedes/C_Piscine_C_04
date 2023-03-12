/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:02:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/03/12 21:56:52 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	base_conversion(int nbr, char *base, int len)
{
	if (nbr > len - 1)
		base_conversion(nbr / len, base, len);
	put_char(base[nbr % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	*buffer;
	int		len;

	len = 0;
	while (*base && *base != '+' && *base != '-')
	{
		buffer = base;
		while (*buffer++)
		{
			if (*buffer == *base)
				return ;
		}
		len++;
		base++;
	}
	if (len > 1 && *base != '+' && *base != '-')
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			put_char('-');
		}
		base_conversion(nbr, base - len, len);
	}
}
