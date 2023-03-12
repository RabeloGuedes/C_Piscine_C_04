/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:02:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/03/12 13:58:28 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}


void	base_conversion(int nbr, int base_len, char *base)
{
	if (nbr > base_len)
		base_conversion(nbr / base_len, base_len, base)l
	put_char(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	i;
	int	i2;

	base_len = 0;
	i = 0;
	while (base[i] && base[i] != '+' && base[i] != '-')
	{
		i2 = i + 1;
		while (base[i2])
		{
			if (base[i] == base[i2])
				return;
		}
		i++;
		base_len++;
	}
	if (base_len > 1 && base[i] != '+' && base[i] != '-')
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			put_char('-');
		}
		base_conversion(nbr, (base_len - 1), base);
	}
}
