/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:33:57 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/24 10:47:12 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char tab[255];
	int i;
	int j;
	int d;

	d = 0;
	i = 0;
	j = 0;

	while (d < 255)
		tab[d++] = 0;
	while (argv[1][i])
	{
		if (tab[(int)argv[1][i]] == 0)
		{
			tab[(int)argv[1][i]] = 1;
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	while (argv[2][j])
	{
		if (tab[(int)argv[2][j]] == 0)
		{
			tab[(int)argv[2][j]] = 1;
			write(1, &argv[2][j], 1);
		}
		j++;
	}
	return (0);
}

/*Ecrire un programme qui prend en parametre deux chaines de caracteres et
qui affiche, sans doublon, les caracteres qui apparaissent
dans l'une ou dans l'autre.
L'affichage doit etre suivi d'un retrour a la ligne.
L'affichage se fera dans l'ordre d'apparition dans la ligne de commande.
Si le nb de parametre trnasmis est different de 2, le programme affiche \n.
Exemple :
./zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy
./ "rien" "cette phrase ne cache rien" | cat -e
rienct phas
./ | cat -e
./ "rien" | cat -e
---------
#include <unistd.h>
int main(int argc, char **argv)
{
    int i;
    int tab[255];
    int j;
    int d;
    i = 0;
    j = 0;
    d = 0;
    if (argc != 3)
        write(1, "\n", 1);
    else
    {
        while (d < 255)
            tab[d++] = 0;
        while (argv[1][i]) // Tu parcours argv[1] == 1er argument, i = les caracteres
        {
            if (tab[(int)argv[1][i]] == 0) // si tab == 0 le caractere jamais rencontrer est a 0, il sera a 1 et ecrira le caractere si il est deja rencontrer
            {
                tab[(int)argv[1][i]] = 1;// tu met le caractere passe a 1
                write(1, &argv[1][i], 1);
            }
            i++;
        }
        while (argv[2][j])
        {
            if (tab[(int)argv[2][j]] == 0)
            {
                tab[(int)argv[2][j]] = 1;
                write(1, &argv[2][j], 1);
            }
            j++;
        }
        write(1, "\n", 1);
    }
}





11:26
Ecrire un programme qui prend en parametre deux chaines de caracteres et
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
----
#include <unistd.h>
int main(int argc, char **argv)
{
    int i;
    int j;
    int d;
    char tab[255];
    i = 0;
    j = 0;
    d = 0;
    if (argc != 3) // argc nb d'arguments
        write(1, "\n", 1);
    else
    {
        while (d < 255)
            tab[d++] = 0; // Remplir un tableau de 0
        while (argv[2][i]) // argv[2] == 2eme arguments, i = les caracteres
        {
            if (tab[(int)argv[2][i]] == 0) // tab[]
                tab[(int)argv[2][i]] = 1;
            i++;
        }
        while (argv[1][j])
        {
            if (tab[(int)argv[1][j]] == 1)
            {
                tab[(int)argv[1][j]] = 2;
                write(1, &argv[1][j], 1);
            }
            j++;
        }
        write(1, "\n", 1);
    }
}*/