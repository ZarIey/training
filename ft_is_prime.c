/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:04:56 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/25 16:23:34 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void ft_is_prime(int nb)
{
	int i;

	i = 2;

	if (nb == 1)
		printf("1");
	else
	{
		while (nb > 1)
		{
			if (nb % i == 0)
			{
				printf("%d", i);
				nb /= i;
				if (nb > i)
					printf("*");
				i--;
			}
			i++;	
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_is_prime(atoi(argv[1]));
	}
	printf("\n");
	return (0);
}
