#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

#include"LSTPRIM.h"

NOEUD noeudCreer(ELEMENT e)
{
    NOEUD n;
    n =(NOEUD)malloc(sizeof(structNoeud));
    if(!n)
        printf ("mémoire insuffisante\a\n");
    else
    {
        ElementAffecter(&n->info, e);
        n->suivant = NULL;
        n->precedent = NULL;
    }
    return n;
}

void noeudDetruire(NOEUD n)
{
    ElementDetruire(n->info);
    free(n);
}

LISTE listeCreer(void)
{
    LISTE L;
    L=(LISTE)malloc(sizeof(lastruct));
    if (! L)
        printf("memoire insuffisante \a\n");
    else
    {
        strcpy( L->nom,"\0");
        L->lg = 0;
        L->tete = NULL;
        L->queu = NULL;
    }
    return(L);
}

void listeDetruire(LISTE L)
{
    int i;
    NOEUD p,q;
    q=L->tete;
    for(i = 1; i <= L->lg; i++)
    {
        p=q;
        q=q->suivant;
        noeudDetruire(p);
    }
    free(L);
}

int estVide(LISTE L)
{
    return(L->lg==0);
}

int estSaturee(LISTE L)
{
    int saturee =1;
    NOEUD m;
    m = (NOEUD)malloc(sizeof(structNoeud));
    if (m!=NULL)
    {
        saturee=0;
        free(m);
    }
    return saturee;
}

int listeTaille(LISTE L)
{
    return (L->lg);
}

ELEMENT recuperer(LISTE L, int pos)
{
    ELEMENT e= ElementCreer();
    int i;
    NOEUD p;
    if (estVide(L))
        printf ("Liste vide :( \a\n");
    else
    {
        if ((pos < 1) || (pos > L->lg))
            printf ("Position invalide :( \a\n");
        else
        {

            p= L->tete;
            for (i=1; i< pos; i++)
                p = p->suivant;

            ElementAffecter(&e,p->info);
        }
    }
    return(e);
}

int inserer (LISTE L, ELEMENT e, int pos)
{
    int succee=1;
    int i;
    NOEUD n, p, q;

    if (estSaturee(L))
    {
        printf ("Liste saturée :( \a\n");
        succee=0;
    }
    else
    {
        if ((pos < 1) || (pos > L->lg + 1))
        {
            printf ("Position invalide :( \a\n");
            succee=0;
        }
        else
        {
            n=noeudCreer (e);

            if (L->lg == 0)
            {
                L->tete = n;
                L->queu = n;
            }
            else
            {
                if (pos == 1)
                {
                    L->tete->precedent = n;
                    n->suivant=L->tete;
                    L->tete = n;
                }
                else
                {
                    if (pos == (L->lg +1))
                    {
                        L->queu->suivant = n;
                        n->precedent = L->queu;
                        L->queu = n;
                    }
                    else
                    {
                        q= L->tete;
                        for (i=1; i<pos; i++)
                        {
                            p = q;
                            q = q->suivant;
                        }
                        p->suivant=n;
                        n->precedent =p;
                        n->suivant=q;
                        q->precedent =n;
                    }
                }
            }
            (L->lg)++;
        }
    }
    return succee;
}

int supprimer(LISTE L, int x)
{
    int i,succee=1;
    NOEUD p,q;

    if (estVide(L))
    {
        printf("liste vide :( \a\n");
        succee =0;
    }
    else if ((x<1)||(x>L->lg))
    {
        printf("position invalide :( \a\n ");
        succee=0;
    }
    else
    {
        if (L->lg==1)
        {
            q=L->tete;
            L->tete=NULL;
            L->queu=NULL;
        }
        else  if (x==1)
        {
            q=L->tete;
            L->tete=L->tete->suivant;
            L->tete->precedent=NULL;
        }
        else if(x==L->lg)
        {
            ElementDetruire(L->queu->info);
            q=L->queu;
            L->queu=L->queu->precedent;
            L->queu->suivant=NULL;
        }
        else
        {
            if (x <= (L->lg/2))
            {
                q=L->tete;
                for(i=1; i<=x-1; i++)
                {
                    p=q;
                    q=q->suivant;
                }
                p->suivant=q->suivant;
                q->suivant->precedent=p;
            }
            else    if (x > (L->lg/2))
            {
                q=L->queu;
                for(i=L->lg; i>=x+1; i--)
                {
                    p=q;
                    q=q->precedent;
                }
                p->precedent=q->precedent;
                q->precedent->suivant=p;
            }
        }
        noeudDetruire(q);
        L->lg--;
    }
    return succee;
}

void listeAfficher(LISTE L)
{
    NOEUD n=L->tete;

    printf("  GOUVERNORAT      DATE     CAS POSITIFS  GUERISONS  DECES  VACCINES \n");
    for(int i=1; i<=L->lg; i++)
    {
        ElementAfficher(n->info);
        n=n->suivant;
    }
    printf("\n");
}

LISTE listeCopier(LISTE L)
{
    LISTE R = listeCreer();
    int i;
    ELEMENT e;
    for(i = 1; i <= L->lg; i++)
    {
        e=ElementCreer();
        ElementCopier(&e, recuperer(L,i));
        inserer(R,e, i);
    }
    return R;
}

int listeComparer(LISTE L1, LISTE L2 )
{
    int test= 1,i=1;
    if (listeTaille(L1) != listeTaille(L2))
        test= 0;
    while ((i<=listeTaille(L1)) && (test))
    {
        if
        (ElementComparer(recuperer(L1,i),recuperer(L2,i))!=0)
            test=0;
        i++;
    }
    return test;
}
