/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex16.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:56:35 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/17 09:11:44 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int atoi(char *str)
{
	int i;
	int sign;
	int nombre;

	i = 0;
	sign = 1;
	nombre = 0;
	while (str[i] > 9 && str[i] < 13)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if str[i] == '-'
			sign *= -1;
	}		
	while (str[i] >= 47 && str[i] <= 59)
		nombre = nombre * 10 + str[i] - 48;
	return (nombre * sign);
}

void put_hexa(int n, base)
{
	char *base;
	base = "0123456789abcdef";
	
	while (n >= 16)
	{
		put_hexa(n / 16, base)
		putchar(base[n % 16]);
	else
		putchar(base[n]);
}
