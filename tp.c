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
        printf("\n%s",first->s);
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
             printf("\n%s",current->s);
            current = current->next;
        }
    }
}


//fonction supprimer

void supprimer_ligne(LISTE ** first , char* s_chaine)
{
    LISTE * current;

if (*first)

    {
        if ( strstr (((*first)->s), s_chaine) == NULL)

        supprimer_ligne(&((*first)->next), s_chaine) ;

        else
        {
            current = *first ;
            *first = (*first)->next ;
           free(current) ;
 supprimer_ligne(&((*first)), s_chaine) ;
        }
    }

}




int main(int argc, char *argv[]) {
    FILE *fp;

    LISTE *first;
    char ligne[200];
     char sous_chaine1 [20], s_chaine [20], sous_chaine2 [20] ;
    if (!(fp = fopen("ahmed.txt", "r++")))
    {


        exit(0);
    }
    first = NULL;


    while (fgets(ligne, 200, fp)) {
        insert_tliste(&first, ligne);

    }

    affiche_tliste(first);

printf ("\n\n \a  donner la chaine a chercher :");
    scanf ("%s", &sous_chaine1);
    recherche_chaine(first, sous_chaine1);

printf("\n\n donner la chaine pour effacer les elts ui contiennet:");
  scanf("%s",&sous_chaine2) ;
supprimer_ligne(&first,sous_chaine2) ;
affiche_tliste(first);
}
