/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:32:42 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/25 16:00:27 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int nb_len(int n)
{
	int len;
	int i;
	long long int nb;

	nb = (long long int)n;
	len = 0;
	i = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		len++;
		//printf("Hello");
		nb /= 10; 
	}
	return (len);
}

char *ft_itoa(int n)
{
	long long int nb;
	int i;
	int len;
	char *inter;

	i = 0;
	nb = 0;
	nb = (long long int)n;
	len = nb_len(nb);
//	printf("---%d\n", len);
	if(!(inter = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb < 0)
	{
		inter[i++] = '-';
		nb *= -1;
	}
	inter[len--] = '\0';
	while (len >= i)
	{
	//	printf("---%d\n", len);
		inter[len--] = nb % 10 + 48;
	//	printf("-%lld\n", nb);
		nb /= 10;
	}
	return(inter);
}

int main ()
{
	printf("%s\n", ft_itoa(123456));
}