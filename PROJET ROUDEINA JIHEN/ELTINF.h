#ifndef ELTINF_H_INCLUDED
#define ELTINF_H_INCLUDED

typedef struct
{
    int j;
    int m;
    int a;
}
DATE;

typedef struct
{
    char gouv[20];
    DATE d;
    int positifs;
    int guerisons;
    int deces;
    int vaccines;
}
gouvernorat,*ELEMENT;

#endif // ELTINF_H_INCLUDED
