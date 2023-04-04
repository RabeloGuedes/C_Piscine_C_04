/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:40:51 by arabelo-          #+#    #+#             */
/*   Updated: 2023/04/04 21:19:56 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	has_char(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
			return (1);
		base++;
	}
	return (0);
}

int	find_index(char c, char *base)
{
	int	index;

	index = 0;
	while (*base)
	{
		if (c == *base)
			return (index);
		base++;
		index++;
	}
	return (-1);
}

int	ft_base_verify(char *base)
{
	int	base_len;
	char *ptr;

	base_len = 0;
	while (*base)
	{
		if (*base == ' ' || *base == '+' || *base == '-'
			|| (*base >= '\t' && *base <= '\r'))
			return (0);
		ptr = base;
		while (*ptr++)
		{
			if (*ptr == *base)
				return (0);
		}
		base_len++;
		base++;
	}
	return (base_len);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	res;
	int	sign;

	base_len = ft_base_verify(base);
	res = 0;
	sign = 1;
	if (base_len < 2)
		return (0);
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		else if (has_char(*str, base))
		{
			while (has_char(*str, base))
			{
				res = res * base_len + find_index(*str, base);
				str++;
			}
			break;
		}
		str++;
	}
	return (sign * res);
}

// #include <stdio.h>

// int ft_atoi_base(char *str, char *base);

// int main(void) {
//     char *str1 = "15";
//     char *base1 = "0123456789abcdef";
//     int result1 = ft_atoi_base(str1, base1);
//     printf("%s in base \"%s\" = %d in base 10\n", str1, base1, result1);

//     char *str2 = "-a";
//     char *base2 = "0123456789abcdef";
//     int result2 = ft_atoi_base(str2, base2);
//     printf("%s in base \"%s\" = %d in base 10\n", str2, base2, result2);

//     char *str3 = "1010";
//     char *base3 = "01";
//     int result3 = ft_atoi_base(str3, base3);
//     printf("%s in base \"%s\" = %d in base 10\n", str3, base3, result3);

//     char *str4 = "deadbeef";
//     char *base4 = "0123456789abcdef";
//     int result4 = ft_atoi_base(str4, base4);
//     printf("%s in base \"%s\" = %d in base 10\n", str4, base4, result4);

//     char *str5 = "123";
//     char *base5 = "01234567";
//     int result5 = ft_atoi_base(str5, base5);
//     printf("%s in base \"%s\" = %d in base 10\n", str5, base5, result5);

// 	char *str6 = "101010";
//     char *base6 = "01";
//     int result6 = ft_atoi_base(str6, base6);
//     printf("%s in base \"%s\" = %d in base 10\n", str6, base6, result6);

//     return 0;
// }
