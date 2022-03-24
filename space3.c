/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:18:40 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/24 17:22:35 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void put_str(char *str)
{
	int i = 0;
	
	while (str[i])
		write(1, &str[i++], 1);
}

int is_space (char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int count_line(char *str)
{
	int i = 0;
	int count = 0;
	
	while (str[i])
	{
		if (str[i] && is_space(str[i]) == 0)
		{
			count++;
			while (str[i] && is_space(str[i]) == 0)
				i++;
		}
		i++;
	}
	return (count);
}

char **ft_split(char *str)
{
	char **split;
	int i = 0;
	int j = 0;
	int len = 0;

	if (!(split = (char **)malloc(sizeof(char *) * count_line(str) + 1)))
		return (NULL);
	while (str[i])
	{
		while (str[i] && (is_space(str[i]) == 1))
			i++;
		while (str[i] && (is_space(str[i]) == 0))
		{
			len++;
			i++;
		}
		if (!(split[j] = malloc(sizeof(char) * len + 1)))
			return (NULL);
		int k = 0;
		while (len)
			split[j][k++] = str[i - len--];
		split[j++][k] = '\0';
	}
	split[j] = NULL;
	return (split);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int len = 0;
	char **inter;
	char *first;

	len = count_line(argv[1]);	
	inter = ft_split(argv[1]);
	first = inter[i];
		
	while (i < len - 1)
		{
			inter[i] = inter [i + 1];
			i++;
		}	
	i = 0;
	inter[len - 1] = first;
	while (len > 1)
	{
		len--;
		put_str(inter[i++]);
		put_str(" ");
	}
	put_str(inter[i]);
}