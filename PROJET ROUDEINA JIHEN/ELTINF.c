#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#include"ELTPRIM.h"

void DateLire(DATE *d)
{
    int test=0;
    printf("Date (jour/mois/annee): ");
    scanf("%i/%i/%i",&(d->j), &(d->m),&(d->a));
    while(!test)
    {
        if(DateCorrect(*d))
            test=1;
        else
        {
            printf("Date Icorrecte\a\n");
            printf("Date (jour/mois/annee): ");
            scanf("%i/%i/%i",&(d->j), &(d->m),&(d->a));
        }
    }
}

int DateCorrect(DATE d)
{
    if(((d.m==1 || d.m==3 || d.m==5 || d.m==7 || d.m==8 || d.m==10 || d.m==12) && (d.j<=31 && d.j>=1)) || ((d.m==4 || d.m==6 || d.m==9 || d.m==11) && (d.j<=30 && d.j>=1)) || (d.m==2 && ((d.j<=28 && d.j>=1) || (d.a%4==0 && d.j<=29 && d.j>=1))))
        return 1;
    else
        return 0;
}

int DateComparer(DATE d1,DATE d2)
{
    int cmp=0;
    if(d1.a!=d2.a)
        cmp=d1.a-d2.a;
    else if(d1.m!=d2.m)
        cmp=d1.m-d2.m;
    else if(d1.j!=d2.j)
        cmp=d1.j-d2.j;
    return cmp;
}

ELEMENT ElementCreer(void)
{
    ELEMENT e;
    e=(ELEMENT)malloc(sizeof(gouvernorat));
    if(!e)
        printf("Element Creer : Probleme De Memoire\a\n");
    else
    {
        strcpy(e->gouv,"\0");
        e->d.j=0;
        e->d.m=0;
        e->d.a=0;
        e->positifs=0;
        e->guerisons=0;
        e->deces=0;
        e->vaccines=0;
    }
    return e;
}

void ElementDetruire(ELEMENT e)
{
    free(e);
}

void ElementLire(ELEMENT*e)
{
    DateLire(&(*e)->d);

    printf("Cas Positifs : ");
    scanf("%i",&((*e)->positifs));

    printf("Guerisons : ");
    scanf("%i",&((*e)->guerisons));

    printf("Deces : ");
    scanf("%i",&((*e)->deces));

    printf("Vaccines : ");
    scanf("%i",&((*e)->vaccines));

}

void ElementAfficher(ELEMENT e)
{
    printf(" %11s   %02i/%02i/%04i  %7i        %5i      %3i    %4i\n",e->gouv,e->d.j,e->d.m,e->d.a,e->positifs,e->guerisons,e->deces,e->vaccines);
}

void ElementAffecter(ELEMENT*e1,ELEMENT e2)
{
    *e1=e2;
}

void ElementCopier(ELEMENT*e1,ELEMENT e2)
{
    **e1=*e2;
}

int ElementComparer(ELEMENT e1,ELEMENT e2)
{
    int cmp=0;
    if(!DateComparer(e1->d,e2->d) && e1->deces==e2->deces && e1->guerisons==e2->guerisons && e1->positifs==e2->positifs && e1->vaccines==e2->vaccines)
        cmp=1;
    return cmp;
}

