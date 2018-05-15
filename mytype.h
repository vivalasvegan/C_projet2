#ifndef  __MY_TYPE__      // afin d'eviter les doubles declarations
#define  __MY_TYPE__

typedef struct{
    char * nom;
}myType;


myType * constructMyType (char*);
void destructMyType(myType*);
void afficheMyType(myType*);

#endif
