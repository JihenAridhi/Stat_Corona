#ifndef ELTPRIM_H_INCLUDED
#define ELTPRIM_H_INCLUDED

#include"ELTSDD.h"

void DateLire(DATE *);
int DateCorrect(DATE);
int DateComparer(DATE,DATE);

ELEMENT ElementCreer(void);
void ElementDetruire(ELEMENT);
void ElementLire(ELEMENT*);
void ElementAfficher(ELEMENT);
void ElementAffecter(ELEMENT*,ELEMENT);
void ElementCopier(ELEMENT*,ELEMENT);
int ElementComparer(ELEMENT,ELEMENT);

#endif // ELTPRIM_H_INCLUDED
