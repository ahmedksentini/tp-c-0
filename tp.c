struct liste
{
	char *s ;
	struct liste *next
};
typedef struct liste LISTE;

#include <stdio.h>



void main ()
{
	FILE *fp ;

LISTE *first ;
char *ligne [200] ;
	if (!openfiles(&fp));
	exit(0) ;
	first=NULL ;

    // creation de la liste
	while (fgets(ligne,200,fp))
	 	{
	 		insert_tliste(&first,ligne) ;

	 	}
    // fin de la creation du liste .

 // affiche toutes la liste la liste
  affiche_tliste(first) ;


}
  // fonction affiche toute la liste
  void affiche_tliste(LISTE *first)
 {
 	LISTE *p ;
 	for (p=first ; p ; p=p->next)
 	 printf-data (p->s) ;

 }


//fonction insertion
 void insert_liste(LISTE**first,char ligne)
 {
   LSITE *p ;
p = ((LISTE*)malloc(sizeof(LISTE)) ;
 p->S=(char*)malloc(strlen(ligne)+1) ;
strcpy(p->s,ligne)
 p->next = *first ;
 *first = p ;
}
//fonction open file

int openfiles (FILE **fp)
{
    if (!(*fp)=fopen("ahmed.txt","r"))
        return (0);
    return (1) ;
}

