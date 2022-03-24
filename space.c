/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:52:06 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/24 15:43:32 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return(1);
	return(0);
}

int put_str(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && is_space(str[i]) == 1)
		i++;
	while (str[i])
	{
		while (str[i] && is_space(str[i]) == 1)
		{
			if (is_space(str[i + 1]) == 0)
				write (1, " ", 1);
			i++;
		}	
		while (str[i] && is_space(str[i]) == 0)
		{
			write(1, &str[i++], 1);	
			count++;
		}
	}
	i++;
	return(count);	
}

int main (int argc, char **argv)
{
	int i;
	int j;
	int len;
	char *inter;
	int count;

	count = 0;
	len = 0;
	i = 0;
	j = 0;
	if (argc == 2)
	{
		//while (argv[1][i])
		//{
			while (is_space(argv[1][i]) == 1 && argv[1][i])
				i++;
			while (is_space(argv[1][i]) == 0 && argv[1][i])
			{
				i++;
				len++;
			}
			printf("%d\n", len);
		//		if (is_space(argv[1][i] == 1))
			while (is_space(argv[1][i] == 1))
				i++;
			inter = malloc(sizeof(char) * len + 1);
			while (len)
				inter[j++] = argv[1][i - len--];
			inter[j] = '\0';
		//}
		//printf("%d\n", i);
	//	printf("%d\n", (int)strlen(argv[1]));
		count = put_str(&argv[1][i]);
		//printf("%d\n", count);
		if (!((int)strlen(argv[1]) == i) && count != 0)
			write (1, " ", 1);
		put_str(inter);
	}
	write (1, "\n", 1);
	return (0);
}

char[999999999999999999999]
char[ly] 


