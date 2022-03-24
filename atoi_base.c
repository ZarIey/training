/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:44:40 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/23 15:04:24by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int is_valid(int c, int base)
{
	char base1[17] = "0123456789abcdef";
	char base2[17] = "0123456789ABCDEF";

	while (base--)
		if (c == base1[base] || c == base2[base])
			return (1);
		return (0);
}

int	value_of(char c)
{
	if (c >= 0 || c <= 9)
		return (c - 48);
	if (c >= 'a' || c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' || c <= 'F')
		return (c - 'A' + 10);
}

int atoi_base(char *str, int str_base)
{
	int i;
	int nombre;
	int sign;

	i = 0;
	nombre = 0;
	sign = 1;
	while (str[i] <= 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
		}
		while (is_valid(str[i], str_base))
			nombre = nombre * 16 + value_of(str[i++]);
	return (sign * nombre);
}

int main (int argc, char **argv)
{
	char *str = "627598";
	int str_base = 16;
	printf("%d\n", atoi_base(str, str_base));
	return (0);
}