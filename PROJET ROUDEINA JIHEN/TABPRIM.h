#ifndef TABPRIM_H_INCLUDED
#define TABPRIM_H_INCLUDED

#include"TABSDD.h"

TAB tabCreer(void);
void tabDetruire(TAB);
int esttabVide(TAB);
int esttabSaturee(TAB);
int tabTaille(TAB);
LISTE tabrecuperer(TAB, int);
int tabinserer(TAB, LISTE,int);
int tabsupprimer(TAB, int);
void tabAfficher(TAB);
TAB tabCopier(TAB);
int tabComparer(TAB , TAB );

#endif // TABPRIM_H_INCLUDED
