
#include "mytype.h"


myType * constructMyType(char * S){
    myType * K = malloc(sizeof (mytype));
    K->nom=malloc((strlen(S)+1) * sizeof(char)); // taille chaîne * nb car.
    strcpy(K->nom, S);
    return K;
}


void   destructMyType( myType * K )
{
    free(K->nom);
    free(K);
}

void   afficheMyType( myType * K) {
    printf( "%s\n" , K->nom );
}

