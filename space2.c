/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:45:20 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/24 16:16:19 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	if ((c >= 9 || c <= 13) || c == 32)
		return (1);
	return (0);
}

void put_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]) == 1)
			i++;
		while (str[i] && is_space(str[i]) == 0)
		{
			write(1, &str[i], 1);
			if (str[i] && is_space(str[++i]) == 1)
			{
				write(1, " ", 1);
				while (str[i] && is_space(str[i]) == 1)
					i++;
			}
			write(1, &str[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int len;
	char inter[4000];
	
	i = 0;
	j = 0;
	k = 0;
	len = 0;
	while (argv[1][i])
	{
		while (argv[1][i] && is_space(argv[1][i]) == 1)
			i++;
		while (argv[1][i] && is_space(argv[1][i]) == 0)
	 	{
		 	len++;
		 	i++;
		}
		// i - len est le debut du mot
		k = i - len;
		i = 0;
		while (argv[1][k])
			inter[j++] = argv[1][k++];
		inter[j++] = 32;
		while (i < k)
			inter[j] = argv[1][i++];
		inter[j] = '\0';
	}
	put_str(inter);
}