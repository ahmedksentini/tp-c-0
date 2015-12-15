#include <stdio.h>
#include <stdlib.h>

struct liste {
    char *s;
    struct liste *next;
};
typedef struct liste LISTE;

// fonction affiche toute la liste
void affiche_tliste(LISTE *first)
{

   if (first)
   {

   affiche_tliste(first->next) ;
        printf("%s",first->s);
   }
}

//fonction insertion
void insert_tliste(LISTE **first, char *ligne) {
    LISTE *p;
    p = (LISTE *) malloc(sizeof(LISTE));
    p->s = (char *) malloc(sizeof(char) * (strlen(ligne) + 1));
    strcpy(p->s,ligne);
    p->next = *first;
    *first = p;
}

//fonction recherche qui recherche ou se trouve une chaine

void recherche_chaine( LISTE * first, char* s_chaine)
{
    LISTE * current;
    current =  first;
    while (current != NULL)
    {
        if ( strstr ((current->s), s_chaine) == NULL)
        current = current ->next;
        else
        {
             printf("%s",current->s);
            current = current->next;
        }
    }
}
int main(int argc, char *argv[]) {
    FILE *fp;

    LISTE *first;
    char ligne[200];
     char sous_chaine [20], s_chaine [20] ;
    if (!(fp = fopen("ahmed.txt", "r")))
    {


        exit(0);
    }
    first = NULL;

    // creation de la liste
    while (fgets(ligne, 200, fp)) {
        insert_tliste(&first, ligne);

    }
    // fin de la creation du liste .

    // affiche toutes la liste la liste
    affiche_tliste(first);

printf ("\n\n \a  donner la chaine a chercher :");
    scanf ("%s", &sous_chaine[0]);
    recherche_chaine(first, sous_chaine);
    return 0;
}

