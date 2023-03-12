/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:02:58 by arabelo-          #+#    #+#             */
/*   Updated: 2023/03/12 14:34:57 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	base_conversion(int nbr, int base_len, char *base)
{
	if (nbr > base_len - 1)
		base_conversion(nbr / base_len, base_len, base);
	put_char(base[nbr % base_len]);
}

void	iteration(int nbr, char *base, int i, int base_len)
{
	if (base_len > 1 && base[i] != '+' && base[i] != '-')
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			put_char('-');
		}
		base_conversion(nbr, base_len, base);
	}
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
				return ;
			i2++;
		}
		i++;
		base_len++;
	}
	iteration(nbr, base, i, base_len);
}

int main(void)
{
    ft_putnbr_base(42, "0123456789");
    put_char('\n');
    ft_putnbr_base(42, "01");
    put_char('\n');
    ft_putnbr_base(42, "0123456789abcdef");
    return (0);
}
