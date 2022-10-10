#ifndef LSTINF_H_INCLUDED
#define LSTINF_H_INCLUDED

#include"ELTPRIM.h"

typedef struct  structNoeud
{
    ELEMENT info ;
    struct structNoeud * precedent ;
    struct structNoeud * suivant ;
} structNoeud, *NOEUD ;

typedef struct
{
    char nom[30];
    NOEUD tete  ;
    NOEUD queu ;
    int lg ;

} lastruct, *LISTE ;

#endif // LSTINF_H_INCLUDED
