/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:23:52 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/24 11:42:02 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Ecrire un programme qui prend en parametre deux chaines de caracteres et
qui affiche, sans doublon, les caracteres communs aux deux chaines.
L'affichage doit etre suivi d'un retrour a la ligne.
L'affichage se fera dans l'ordre d'apparition dans la ligne de commande.
Si le nb de parametre transmis est different de 2, le programme affiche \n.
Exemple :
./zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto
./ "rien" "cette phrase ne cache rien" | cat -e
rien
./ | cat -e
./ "rien" | cat -e
---- */
#include <unistd.h>

int main(int argc, char **argv)
{
	int tab[255];
	int i;
	int j;
	int d;
	
	i = 0;
	j = 0;
	d = 0;

	if (argc == 3)
	{
		while (d < 255)
			tab[d++] = 0;
		while (argv[2][j])
		{
			if (tab[(int)argv[2][j]] == 0)
				(tab[(int)argv[2][j]] = 1);
			j++;
		}
		while (argv[1][i])
		{	
			if (tab[(int)argv[1][i]] == 1)
			{
				(tab[(int)argv[1][i]] = 2);
				write(1, &argv[1][i], 1);
			} 
		i++;
		}
	}
	write (1, "\n", 1);
}