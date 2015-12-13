struct liste 
{
	char *s ;
	struct liste *next
};
typedef struct liste LISTE ;

#include <stdio.h>
#include <sting.h>


void main () 
{
	FILE *fp ;
	
	LSITE *first ;
	
	if (!openfiles(&fp));
	exit() ;
	first=null ;
   
    // creation de la liste 	
	while (fgets (ligne,1000,fp))
	 	{
	 		insert-liste(&first,ligne) ;
	 		
	 	}
    // fin de la creation du liste .
 
 // affiche toutes la liste la liste 
  affiche-tliste(first) ;
  
 
}
  // fonction affiche toute la liste 
  void affiche-tliste(LISTE *first)
 {
 	LISTE *p ;
 	for (p=first ; p ; p=p->next)
 	 printf-data (p->s) ;
 	
 }
   

//fonction insertion
 void insert-liste(LISTE**first,char ligne)
 { 
   LSITE *p ;
p = ((LISTE*)malloc(sizeof(LISTE)) ;
 p->S=(char*)malloc(strlen(ligne)+1) ;
strcpy(p->s,ligne)
 p->next = *first ;
 *first = p ;
}
