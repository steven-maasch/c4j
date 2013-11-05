#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include "rationalnumber.h"

struct RationalNumberCollection;

RationalNumberCollection *rncCreate(int);

void rncDelete(RationalNumberCollection *);

void rncAdd(RationalNumberCollection *, RationalNumber);

void rncRemove(RationalNumberCollection *, RationalNumber);

int rncCount(RationalNumberCollection *, RationalNumber);

int rncTotalUniqueCount(RationalNumberCollection *);

int rncTotalCount(RationalNumberCollection *);

RationalNumber rncSum(RationalNumberCollection *);

RationalNumber rncAverage(RationalNumberCollection *);

int rncGetCapacity(RationalNumberCollection *);

#endif // RATIONALNUMBERCOLLECTION_H
