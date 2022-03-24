/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex216.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:19:42 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/24 12:49:51 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_char(char c)
{
	write(1, &c, 1);
}

int ft_atoi(char *str)
{
	int i;
	int nombre;
	int sign;
	
	sign = 1;
	nombre = 0;
	i = 0;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nombre = nombre * 10 + str[i] - 48;
		i++;
	}
	return (nombre * sign);
}

void put_hex(int nb, char *base)
{
	int i;
	
	base = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
	{
		put_hex(nb / 16, base);
		put_char(base[nb % 16]);
	}
	else
		put_char(base[nb]);
}

int main (int argc, char **argv)
{
	char *base = "0123456789abcdef";
	put_hex(ft_atoi(argv[1]), base);
	return (0);
}