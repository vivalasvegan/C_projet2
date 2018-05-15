#include <stdio.h>
#include <stdlib.h>
#include "tabdyn.h"

#define SIZE 10
#define AUGMENTE 10


int size, top ;

// ======================== privee ==============================

void  afficherType(myType x ) {
    printf( "%d \n" , x ) ;
    
}

void augmente (tabDyn * TD) {
    // TD->size += AUGMENTE ;
    // TD->T = realloc (TD->T , TD->size );
    TD->T = realloc (TD->T , TD->size += AUGMENTE );
}

// ======================== public ==============================

/* --- L'init. Il faut créé dynamiquement un tableau de SIZE entiers --- */
tabDyn * constructTabDyn() {
    tabDyn * TD;
    TD = (tabDyn *) malloc(sizeof(tabDyn)); // On alloue de la mémoire pour le tableau
    TD->T = malloc(sizeof(myType*) * (TD->size = SIZE)) ;
    if (TD == NULL) // On vérifie si l'allocation a marché ou non
    {  printf( "crash now\n" );
        exit(0); // On arrête tout
    }
    TD->top = 0 ;
    return TD ;
}

/* --- Detruire le tableau --- */
void   destructTabDyn (tabDyn * TD) {
    int i ;
    for(i=0 ; i<TD->top ; i++)
        destructMyType(TD->T[i] ); // supprime l'element i
}


/* --- Affichage du tableau --- */
void   afficheTabDyn(tabDyn * TD) {
    int i ;
    for ( i = 0 ; i < TD->top ; i++ ) afficheMyType( TD->T[i] ) ;
}


/* --- Ajout une valeur. Le tableau peut etre agrandit, donc pt modifie --- */
void   ajout( tabDyn * TD , myType * v) {
    // Vérifier si c'est plein
    if ( TD->top >= TD->size ) augmente( TD ) ;
    // TD->T[TD->top] = v;
    // TD->top++;
    TD->T[TD->top++] = v;
}


/* --- Rend la position ou on a ajoute une valeur --- */
int    getFinAdd( tabDyn * TD )
{
    return TD ->top ;
}

/* --- rend la taille du tableau --- */
int    getSize( tabDyn * TD )
{
    return size;
}

/* --- rend la valeur à la position du tableau --- */
myType getVal( tabDyn * TD, int i)
{
    return TD[i] ;
}



/* --- rend vrai si on est a la fin du tableau --- */
int    isEnd( )
{
    if (top == size)
        return 1;
    return 0;
}


/* --- rend vrai si on est au debut du tableau --- */
int    isEmpty() {
    
    if (top == 0)
        return 1;
    return 0;
}


tabDyn * constructTabDyn () {
    tabDyn * X = malloc (sizeof (tabDyn));
    //X->T = malloc(sizeof (mytype*));
    X->TD = NULL;
    X->Size = 0;
    X->top = 0 ;
    return X;
}

void destructeurTabDyn( tabDyn ** X )
{
    (*X)->Size=0;
    (*X)->top=0;
    free((*X)->TD);
    free(*X);
}


void ajoutTabDyn (tabDyn ** X ,mytype * TAB){
    (*X)->TD = realloc ((*X)->TD,1 * sizeof(mytype*));
    (*X)->TD[(*X)->top]=TAB;
    (*X)->top  += 1;
    (*X)->Size += 1;
}

void AfficheTabDyn(tabDyn * X){
    mytype** tmp = X->TD;
    int i ;
    for ( i = 0 ; i <X->Size ; i++ )
        afficheMytype(tmp[i]);
}

