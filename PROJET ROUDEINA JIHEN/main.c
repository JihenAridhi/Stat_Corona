#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include<time.h>
#include<ctype.h>

#include"TABPRIM.h"

int menu(TAB T);
void SAISIRE (TAB T);
void MODIFIER (TAB T);
void SUPPRIMER (TAB T);
int AFFICHER (TAB T);
void ListeTrier(TAB T);
void GouverTrier(TAB T);
void tri(LISTE L);
void permut(ELEMENT e1,ELEMENT e2);
void fichier(TAB T);

int main()
{

    //pour changer les valeurs des elements à chaque fois
    srand(time(NULL));
    //declaration
    TAB T=tabCreer();
    ELEMENT e;

    for(int i=1; i<=24; i++)
        T->gouv[i]=listeCreer();
    strcpy(T->gouv[1]->nom, "ARIANA");
    strcpy(T->gouv[2]->nom, "BEJA");
    strcpy(T->gouv[3]->nom,"BENAROUS");
    strcpy(T->gouv[4]->nom,"BENZART");
    strcpy(T->gouv[5]->nom,"EL-KEF");
    strcpy(T->gouv[6]->nom,"GABES");
    strcpy(T->gouv[7]->nom,"GAFSA");
    strcpy(T->gouv[8]->nom,"GASSRINE");
    strcpy(T->gouv[9]->nom,"GBELLI");
    strcpy(T->gouv[10]->nom,"JENDOUBA");
    strcpy(T->gouv[11]->nom,"KEROUAN");
    strcpy(T->gouv[12]->nom,"MAHDIYA");
    strcpy(T->gouv[13]->nom,"MANOUBA");
    strcpy(T->gouv[14]->nom,"MEDNINE");
    strcpy(T->gouv[15]->nom,"MONASTIR");
    strcpy(T->gouv[16]->nom,"NABEL");
    strcpy(T->gouv[17]->nom,"SFAX");
    strcpy(T->gouv[18]->nom,"SIDI-BOUZID");
    strcpy(T->gouv[19]->nom,"SILIANA");
    strcpy(T->gouv[20]->nom,"SOUSSE");
    strcpy(T->gouv[21]->nom,"TATAOUIN");
    strcpy(T->gouv[22]->nom,"TOUZER");
    strcpy(T->gouv[23]->nom,"TUNIS");
    strcpy(T->gouv[24]->nom,"ZAGHOUEN");

    for(int i=1; i<=24; i++)
    {
        for(int j=1; j<=20; j++)
        {
            e = ElementCreer();
            e->d.j=j;
            e->d.m=03;
            e->d.a=2021;
            e->positifs= rand()%1000;
            e->guerisons=rand()%100;
            e->deces=rand()%100;
            e->vaccines=rand()%100;
            strcpy(e->gouv,T->gouv[i]->nom);
            inserer(T->gouv[i],e,j);
        }
        tabinserer(T,T->gouv[i],i);
    }

    printf("\n\n  ********************BIENVENUE********************\n");
    menu(T);

    return 0;
}

int menu (TAB T)
{
    int choix;
    printf("\n         1-Saisir Des Nouveaux Statistiques\n\n");
    printf("             2-Modifier Des Coordonnees\n\n");
    printf("             3-Supprimer Des Coordonnees\n\n");
    printf("             4-afficher les statistiques\n\n");
    printf("   5-Trier Les Statistiques Selon Une Date Donnee\n\n");
    printf("     6-Trier Les Statistiques D'un Gouvernorat\n\n");
    printf("        7-Saisir Des Coordonees D'un Fichier\n\n");
    printf("                      8-Quitter\n\n");
    scanf("%i",&choix);
    system("cls");
    switch(choix)
    {
        case 1 : SAISIRE (T); break;
        case 2 : MODIFIER(T); break;
        case 3 : SUPPRIMER(T); break;
        case 4 : AFFICHER(T); break ;
        case 5 : ListeTrier(T) ; break;
        case 6 : GouverTrier(T); break;
        case 7 : fichier(T); break;
        case 8 : { printf("\n\n  ********************AU REVOIR********************\n\n"); return 0; }
        default : printf("CHOIX INVALIDE \a\nRESSAYER : " ); break;
    }
    return menu(T);
}

void SAISIRE (TAB T)
{
    int i;
    ELEMENT e =ElementCreer();
    DateLire(&(e->d));

    for(i=1; i<=24; i++)
    {
        int j=1,test=0;
        while(j<=listeTaille(T->gouv[i]) && !test)
        {
            if(DateComparer(e->d,recuperer(T->gouv[i],j)->d)<0)
                test=1;
            else if(DateComparer(e->d,recuperer(T->gouv[i],j)->d)==0)
            {
                printf("DATE EXISTANTE !\a\nRESSAYER : \n");
                DateLire(&(e->d));
                j=0;
            }
            j++;
        }
        printf("%s : \n",T->gouv[i]->nom);
        printf("Donner Le Nombre Des Cas Positifs :) \n ");
        scanf("%i",&(e->positifs));
        printf("Donner Le Nombre Des Guerisons :) \n ");
        scanf("%i",&(e->guerisons));
        printf("Donner Le Nombre Des Deces :) \n ");
        scanf("%i",&(e->deces));
        printf("Donner Le Nombre Des Vaccinees :) \n ");
        scanf("%i",&(e->vaccines));
        inserer(T->gouv[i],e,j);
        system("cls");
    }
}

void MODIFIER (TAB T)
{
    char gouver [30];
    int trouve =0;
    int i,j;
    DATE l;
    NOEUD a;

    DateLire(&l);
    printf("Donner Le Gouvernorat : ");
    scanf("%s",gouver);
    i=1;
    while((i<=24)&&(!trouve))
    {
        if(strcmp(T->gouv[i]->nom,gouver)==0)
        {
            trouve =1;
            a=T->gouv[i]->tete;

            for(j=1; j<T->gouv[j]->lg; j++)
            {
                if(DateComparer(a->info->d,l)==0)
                {
                    printf("Avant La Modification Des Coordon%ces : \n\n",130);
                    printf("Nombre Des Cas Positifs : %i \n",a->info->positifs);
                    printf("Nombre Des Gu%crisons :%i \n", 130, a->info->guerisons);
                    printf("Nombre De D%cc%cs :%i \n", 130,138,a->info->deces  );
                    printf("Nombre Des Vaccin%cs : %i \n\n",130,a->info->vaccines );

                    printf("Apr%cs La Modification : \n\n", 130);

                    printf("Donner Le Nombre De Cas Positifs :) ");
                    scanf("%i",&((a)->info->positifs));
                    printf("Donner Le Nombre Des Gu%crisons :) ", 130);
                    scanf("%i",&((a)->info->guerisons));
                    printf("Donner Le Nombre De D%cc%cs :) ", 130,138 );
                    scanf("%i",&((a)->info->deces));
                    printf("Donner Le Nombre Des Vaccin%cs :) ",130);
                    scanf("%i",&((a)->info->vaccines));
                    system("cls");
                }
                a=a->suivant;
            }
        }
        else i++;
    }
}

void SUPPRIMER (TAB T)
{
    int trouve =0,i,j;
    char gouver [30];
    DATE P;
    DateLire(&P);

    printf("donner le gouvernorat demand%c \n",130);
    scanf("%s",gouver);

    ELEMENT r =ElementCreer();
    i=1;
    while((i<=24)&&(!trouve))
    {
        if(strcmp(T->gouv[i]->nom,gouver)==0)
        {
            trouve =1;
            for(j=1; j<T->gouv[i]->lg; j++)
            {
                r= recuperer(T->gouv[i],j);
                if(DateComparer(r->d,P)==0)
                    supprimer(T->gouv[i],j);
            }
            listeAfficher(T->gouv[i]);
        }
        else i++;
    }
}

int AFFICHER (TAB T)
{
    char gouver [30] ;
    int i,A ;
    printf("\n\n 1-Afficher Les Statistiques De Tous Les Gouvernorats \n");
    printf(" 2-Afficher Les Statistiques D'une Gouvernorat \n");
    printf(" 3-Quitter\n\n");
    scanf("%i",&A);
    system("cls");
    switch(A)
    {
    case 1 :
        tabAfficher(T);
        break;
    case 2 :
    {
        printf("Donner Le Gouvernorat Demand%c \n",130);
        scanf("%s",gouver);
        system("cls");
        i=1;
        for(i=1; i<=24; i++)
            if(strcmp(T->gouv[i]->nom,gouver)==0)
                listeAfficher(T->gouv[i]);
    }
    break;
    case 3 :
        return 0;
    default :
        printf("CHOIX INVALIDE \a\nRESSAYER : " );
        break;
    }
    return AFFICHER(T);
}

void ListeTrier(TAB T)
{
    LISTE L1=listeCreer();
    DATE d;

    DateLire(&d);

    for(int i=0; i<24; i++)
    {
        int j=1;
        while(j<=listeTaille(T->gouv[i]) && DateComparer(d,recuperer(T->gouv[i],j)->d)!=0)
            j++;
        if(j<=listeTaille(T->gouv[i]))
            inserer(L1,recuperer(T->gouv[i],j),listeTaille(L1)+1);
    }
    system("cls");
    tri(L1);
}
void GouverTrier(TAB T)
{
    char nom[20];

    printf("DONNER UN GOUVERNORAT : ");
    scanf("%s",nom);
    int i=0,test=0;
    while(i<24 && !test)
    {
        int j=0;
        while(j<strlen(T->gouv[i]->nom) && (T->gouv[i]->nom)[j]==toupper(nom[j]))
            j++;
        if(j==strlen(T->gouv[i]->nom))
            test=1;
        else
            i++;
    }
    system("cls");
    tri(T->gouv[i]);
}

void tri(LISTE L)
{
    ELEMENT e1,e2;
    int j=listeTaille(L);
    int choix;

    int positifs,guerisons,deces,vaccines;
    printf("ORGANISER CES CRITERES : \n");

    printf("Cas Positifs : ");
    scanf("%i",&positifs);

    printf("Guerisons : ");
    scanf("%i",&guerisons);

    printf("Deces : ");
    scanf("%i",&deces);

    printf("Vaccines : ");
    scanf("%i",&vaccines);

    printf("\nORDRE : \n1-Croissant\n2-Decroissant\n");
    scanf("%i",&choix);
    system("cls");

    while(j>0)
    {
        for(int i=1; i<j; i++)
        {
            if(choix==1)
            {
                e2=recuperer(L,i);
                e1=recuperer(L,i+1);
            }
            else if(choix==2)
            {
                e1=recuperer(L,i);
                e2=recuperer(L,i+1);
            }

            if(positifs==1)
            {
                if(e1->positifs<e2->positifs)
                    permut(e1,e2);
                else if(e1->positifs==e2->positifs)
                {
                    if(guerisons==2)
                    {
                        if(e1->guerisons<e2->guerisons)
                            permut(e1,e2);
                        else if(e1->guerisons==e2->guerisons)
                        {
                            if(deces==3)
                            {
                                if(e1->deces<e2->deces)
                                    permut(e1,e2);
                                else if(e1->deces==e2->deces)
                                {
                                    if(e1->vaccines<e2->vaccines)
                                        permut(e1,e2);
                                }
                            }

                            if(vaccines==3)
                            {
                                if(e1->vaccines<e2->vaccines)
                                    permut(e1,e2);
                                else if(e1->vaccines==e2->vaccines)
                                {
                                    if(e1->deces<e2->deces)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                    if(deces==2)
                    {
                        if(e1->deces<e2->deces)
                            permut(e1,e2);
                        else if(e1->deces==e2->deces)
                        {
                            if(guerisons==3)
                            {
                                if(e1->guerisons<e2->guerisons)
                                    permut(e1,e2);
                                else if(e1->guerisons==e2->guerisons)
                                {
                                    if(e1->vaccines<e2->vaccines)
                                        permut(e1,e2);
                                }
                            }
                            if(vaccines==3)
                            {
                                if(e1->vaccines<e2->vaccines)
                                    permut(e1,e2);
                                else if(e1->vaccines==e2->vaccines)
                                {
                                    if(e1->guerisons<e2->guerisons)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                    if(vaccines==2)
                    {
                        if(e1->vaccines<e2->vaccines)
                            permut(e1,e2);
                        else if(e1->vaccines==e2->vaccines)
                        {
                            if(deces==3)
                            {
                                if(e1->deces<e2->deces)
                                    permut(e1,e2);
                                else if(e1->deces==e2->deces)
                                {
                                    if(e1->guerisons<e2->guerisons)
                                        permut(e1,e2);
                                }
                            }
                            if(guerisons==3)
                            {
                                if(e1->guerisons<e2->guerisons)
                                    permut(e1,e2);
                                else if(e1->guerisons==e2->guerisons)
                                {
                                    if(e1->deces<e2->deces)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                }
            }
            if(guerisons==1)
            {
                if(e1->guerisons<e2->guerisons)
                    permut(e1,e2);
                else if(e1->guerisons==e2->guerisons)
                {
                    if(positifs==2)
                    {
                        if(e1->positifs<e2->positifs)
                            permut(e1,e2);
                        else if(e1->positifs==e2->positifs)
                        {
                            if(deces==3)
                            {
                                if(e1->deces<e2->deces)
                                    permut(e1,e2);
                                else if(e1->deces==e2->deces)
                                {
                                    if(e1->vaccines<e2->vaccines)
                                        permut(e1,e2);
                                }
                            }
                            if(vaccines==3)
                            {
                                if(e1->vaccines<e2->vaccines)
                                    permut(e1,e2);
                                else if(e1->vaccines==e2->vaccines)
                                {
                                    if(e1->deces<e2->deces)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                    if(deces==2)
                    {
                        if(e1->deces<e2->deces)
                            permut(e1,e2);
                        else if(e1->deces==e2->deces)
                        {
                            if(positifs==3)
                            {
                                if(e1->positifs<e2->positifs)
                                    permut(e1,e2);
                                else if(e1->positifs==e2->positifs)
                                {
                                    if(e1->vaccines<e2->vaccines)
                                        permut(e1,e2);
                                }
                            }
                            if(vaccines==3)
                            {
                                if(e1->vaccines<e2->vaccines)
                                    permut(e1,e2);
                                else if(e1->vaccines==e2->vaccines)
                                {
                                    if(e1->positifs<e2->positifs)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                    if(vaccines==2)
                    {
                        if(e1->vaccines<e2->vaccines)
                            permut(e1,e2);
                        else if(e1->vaccines==e2->vaccines)
                        {
                            if(deces==3)
                            {
                                if(e1->deces<e2->deces)
                                    permut(e1,e2);
                                else if(e1->deces==e2->deces)
                                {
                                    if(e1->positifs<e2->positifs)
                                        permut(e1,e2);
                                }
                            }
                            if(positifs==3)
                            {
                                if(e1->positifs<e2->positifs)
                                    permut(e1,e2);
                                else if(e1->positifs==e2->positifs)
                                {
                                    if(e1->deces<e2->deces)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                }
            }
            if(deces==1)
            {
                if(e1->deces<e2->deces)
                    permut(e1,e2);
                else if(e1->deces==e2->deces)
                {
                    if(positifs==2)
                    {
                        if(e1->positifs<e2->positifs)
                            permut(e1,e2);
                        else if(e1->positifs==e2->positifs)
                        {
                            if(guerisons==3)
                            {
                                if(e1->guerisons<e2->guerisons)
                                    permut(e1,e2);
                                else if(e1->guerisons==e2->guerisons)
                                {
                                    if(e1->vaccines<e2->vaccines)
                                        permut(e1,e2);
                                }
                            }
                            if(vaccines==3)
                            {
                                if(e1->vaccines<e2->vaccines)
                                    permut(e1,e2);
                                else if(e1->vaccines==e2->vaccines)
                                {
                                    if(e1->guerisons<e2->guerisons)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                    if(guerisons==2)
                    {
                        if(e1->guerisons<e2->guerisons)
                            permut(e1,e2);
                        else if(e1->guerisons==e2->guerisons)
                        {
                            if(positifs==3)
                            {
                                if(e1->positifs<e2->positifs)
                                    permut(e1,e2);
                                else if(e1->positifs==e2->positifs)
                                {
                                    if(e1->vaccines<e2->vaccines)
                                        permut(e1,e2);
                                }
                            }
                            if(vaccines==3)
                            {
                                if(e1->vaccines<e2->vaccines)
                                    permut(e1,e2);
                                else if(e1->vaccines==e2->vaccines)
                                {
                                    if(e1->positifs<e2->positifs)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                    if(vaccines==2)
                    {
                        if(e1->vaccines<e2->vaccines)
                            permut(e1,e2);
                        else if(e1->vaccines==e2->vaccines)
                        {
                            if(positifs==3)
                            {
                                if(e1->positifs<e2->positifs)
                                    permut(e1,e2);
                                else if(e1->positifs==e2->positifs)
                                {
                                    if(e1->guerisons<e2->guerisons)
                                        permut(e1,e2);
                                }
                            }
                            if(guerisons==3)
                            {
                                if(e1->guerisons<e2->guerisons)
                                    permut(e1,e2);
                                else if(e1->guerisons==e2->guerisons)
                                {
                                    if(e1->positifs<e2->positifs)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                }
            }
            if(vaccines==1)
            {
                if(e1->vaccines<e2->vaccines)
                    permut(e1,e2);
                else if(e1->vaccines==e2->vaccines)
                {
                    if(positifs==2)
                    {
                        if(e1->positifs<e2->positifs)
                            permut(e1,e2);
                        else if(e1->positifs==e2->positifs)
                        {
                            if(guerisons==3)
                            {
                                if(e1->guerisons<e2->guerisons)
                                    permut(e1,e2);
                                else if(e1->guerisons==e2->guerisons)
                                {
                                    if(e1->deces<e2->deces)
                                        permut(e1,e2);
                                }
                            }
                            if(deces==3)
                            {
                                if(e1->deces<e2->deces)
                                    permut(e1,e2);
                                else if(e1->deces==e2->deces)
                                {
                                    if(e1->guerisons<e2->guerisons)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                    if(guerisons==2)
                    {
                        if(e1->guerisons<e2->guerisons)
                            permut(e1,e2);
                        else if(e1->guerisons==e2->guerisons)
                        {
                            if(positifs==3)
                            {
                                if(e1->positifs<e2->positifs)
                                    permut(e1,e2);
                                else if(e1->positifs==e2->positifs)
                                {
                                    if(e1->deces<e2->deces)
                                        permut(e1,e2);
                                }
                            }
                            if(deces==3)
                            {
                                if(e1->deces<e2->deces)
                                    permut(e1,e2);
                                else if(e1->deces==e2->deces)
                                {
                                    if(e1->positifs<e2->positifs)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                    if(deces==2)
                    {
                        if(e1->deces<e2->deces)
                            permut(e1,e2);
                        else if(e1->deces==e2->deces)
                        {
                            if(positifs==3)
                            {
                                if(e1->positifs<e2->positifs)
                                    permut(e1,e2);
                                else if(e1->positifs==e2->positifs)
                                {
                                    if(e1->guerisons<e2->guerisons)
                                        permut(e1,e2);
                                }
                            }
                            if(guerisons==3)
                            {
                                if(e1->guerisons<e2->guerisons)
                                    permut(e1,e2);
                                else if(e1->guerisons==e2->guerisons)
                                {
                                    if(e1->positifs<e2->positifs)
                                        permut(e1,e2);
                                }
                            }
                        }
                    }
                }
            }
        }
        j--;
    }

    listeAfficher(L);
}
void permut(ELEMENT e1,ELEMENT e2)
{
    ELEMENT aux=ElementCreer();

    ElementCopier(&aux,e1);
    ElementCopier(&e1,e2);
    ElementCopier(&e2,aux);
}

void fichier(TAB T)
{
    FILE *f;
    char filename[100],str[40],m[8][12];
    ELEMENT e;
    printf("Donner Le Chemin De Fichier : ");
    scanf("%s",filename);

    f=fopen(filename,"r");
    while(fgets(str,40,f)!=NULL)
    {
        e=ElementCreer();
        int j=0,k=0;
        for(int i=0; i<40; i++)
        {
            if(str[i]!='#')
                m[j][k]=str[i];
            else
            {
                m[j][k]='\0';
                j++;
                k=-1;
            }
            k++;
        }

        strcpy(e->gouv,m[0]);
        e->d.j=atoi(m[1]);
        e->d.m=atoi(m[2]);
        e->d.a=atoi(m[3]);
        e->positifs=atoi(m[4]);
        e->guerisons=atoi(m[5]);
        e->deces=atoi(m[6]);
        e->vaccines=atoi(m[7]);
        ElementAfficher(e);

        int i=0;
        while(i<24 && strcmp(e->gouv,T->gouv[i]->nom))
            i++;
        if(i<24)
        {
            int j=1;
            while(j<=listeTaille(T->gouv[i]) && DateComparer(e->d,recuperer(T->gouv[i],j)->d)>0)
                j++;

            if(j<=listeTaille(T->gouv[i]) && j!=1)
                supprimer(T->gouv[i],j);
            inserer(T->gouv[i],e,j);
        }
        listeAfficher(T->gouv[i]);
    }
}
