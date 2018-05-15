#include <stdio.h>
#include <stdlib.h>
#include "tabdyn.h"


char * Mot[]= {"coucou", "salut", "hello"};
int main()
{
    int i , size = sizeof(Mot)/sizeof(char *);
    tabDyn * TD =constructTabDyn ();
    
    for (i=0; i<size;i++)
        ajout( TD,constructMyType(Mot[i]) );
    
    afficheTabDyn(TD);
    destructTabDyn(TD);
    free(TD);
    
    return 0;
}
