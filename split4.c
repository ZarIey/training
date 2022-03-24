/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:43:07 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/24 17:03:29 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int count_line (char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			count++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
		i++;
	}
	return (count);
}

char **ft_split(char *str)
{
	int i;
	int j;
	int len;
	int k;
	char **split;

	i = 0;
	j = 0;
	len = 0;
	if (!(split = (char **)malloc(sizeof(char *) * count_line(str) + 1)))
		return (NULL);
	while (str[i] && j < count_line(str))
	{
		while (str[i] && is_space(str[i]))
			i++;
		while (str[i] && !is_space(str[i]))
		{
			len++;
			i++;
		}
		k = 0;
		if (!(split[j] = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (len)
			split[j][k++] = str[i - len--];
		split[j++][k] = '\0';
	}
	split[j] = NULL;
	return (split);
}

int main(void)
{
	char	*str = "Bonjour\ta\ntous les\tpetits\tloups         ";
	int		i;
	char	**result;

	result = ft_split(str);
	i = 0;
	while (result[i])
		printf("%s\n", result[i++]);
}