#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char const *argv[])
{
	int nombreMystere = 1, proposition = 0, nbCoups = 0, nbMAX = 0, niveau = 0;
	char reponse = 'N';
	const int NBMIN = 0;

//Menu Difficulte du jeu
    do
        {
        printf("Difficulte du jeu ? \n 1. Easy \n 2. Medium \n 3. Hard \n\n");
        scanf("%d", &niveau);
        switch (niveau)
        {
            case 1:
                nbMAX   =   100;
                break;
            case 2:
                nbMAX   =   1000;
                break;
            case 3:
                nbMAX   =   10000;
                break;
            default:
                printf("Erreur, le niveau saisi n'existe pas");
                break;
        }
    } while (nbMAX == 0);
//Generateur Aleatoire
	srand(time(NULL));

//Calcul nb mystere
	nombreMystere = (rand() % (nbMAX - NBMIN - 1)) - NBMIN;

//Boucle principale
	do
	{
//On demande le nombre
		printf("Tapez votre proposition : ");
		scanf("%d", &proposition);
		nbCoups++;
//On répond à la proposition
		if (proposition == nombreMystere)
			{
			printf("Bravo, vous avez gagne ! en %d coups ! \n\n", nbCoups);
			printf("Voulez vous faire une nouvelle partie ? (O = Oui)");
			scanf("%s", &reponse);
			if (reponse == 'O')
                {
                proposition = -1;
                nombreMystere = (rand() % (nbMAX - NBMIN)) - NBMIN;
                nbCoups = 0;
                }
            else
                return 0;
			}
        else if (proposition < nombreMystere)
			printf("C'est plus !! \n\n");
		else
			printf("C'est moins ! \n\n");

	} while (nombreMystere != proposition);
	return 0;
}
