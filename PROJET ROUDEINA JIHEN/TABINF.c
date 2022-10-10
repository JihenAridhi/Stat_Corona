#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include"TABPRIM.h"

TAB tabCreer(void)
{
    TAB t;
    t=(TAB)malloc(sizeof(laStruct));
//if(!t)
    //  {printf("memoire insuffisante :( \n");}
//else
    t->LG=0;
    return(t);
}
void tabDetruire(TAB t)
{
    int i;
    for(i = 1; i <= t->LG ; i++)
        listeDetruire(t->gouv[i]);
    free(t);
}

void tabAfficher(TAB t)
{
    for(int i=1;i<=24;i++)
        listeAfficher(t->gouv[i]);
}

int esttabVide(TAB t)
{
    return(t->LG==0);
}

int esttabSaturee(TAB t)
{
    return(t->LG==24);
}

int tabTaille(TAB t)
{
    return (t->LG);
}

LISTE tabrecuperer(TAB t, int pos)
{
    LISTE L =listeCreer();
    if (esttabVide(t))
        printf ("liste est vide :( \a\n");
    else
    {
        if ((pos < 1) || (pos > t->LG))
            printf ("position invalide :( \n");
        else
            L=(t->gouv[pos]);
    }
    return(L);
}

int tabinserer(TAB t, LISTE L,int pos)
{
    int i;
    int succee=1;

    if (esttabSaturee(t))
    {
        printf ("Liste saturée :( \a\n");
        succee=0;
    }
    else
    {
        if ((pos < 1) || (pos > t->LG + 1))
        {
            printf ("Position invalide :( \n");
            succee=0;
        }
        else
        {
            for(i = t->LG; i>= pos; i--)
                t->gouv[i+1]=listeCopier(t->gouv[i]);
            t->gouv[pos]=listeCopier(L);
            (t->LG)++;
        }
    }
    return(succee);
}

int tabsupprimer (TAB t, int pos )
{
    int i;
    int succee=1;

    if (esttabVide(t))
    {
        printf ("Liste vide :( \n");
        succee=0;
    }
    else
    {
        if ((pos < 1) || (pos > t->LG))
        {
            printf ("Position invalide :( \n");
            succee=0;
        }
        else
        {
            listeDetruire(t->gouv[pos]);
            for(i=pos; i<=t->LG; i++)
                t->gouv[i]=t->gouv[i+1];
            (t->LG)--;
        }
    }
    return(succee);
}


TAB tabCopier(TAB t)
{
    TAB R=tabCreer();
    int i;
    LISTE L;

    for(i = 1; i <= t->LG; i++)
    {
        L=listeCreer();
        L=listeCopier( tabrecuperer(t,i));
        tabinserer(R, L, i);
    }
    return R;
}

int tabComparer(TAB t1, TAB t2 )
{
    int test= 1;
    int i=1;
    if (tabTaille(t1) != tabTaille(t2)) test= 0;
    while ((i<=tabTaille(t1)) && (test))
    {
        if (listeComparer(tabrecuperer(t1,i),tabrecuperer(t2,i))!=0)
            test=0;
        i++;
    }
    return test;
}
