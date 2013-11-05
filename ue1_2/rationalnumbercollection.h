#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include "rationalnumber.h"

struct RationalNumberCollectionComponent {
    RationalNumber r;
    int counter;
};

struct RationalNumberCollection {
    RationalNumberCollectionComponent collection [1000];
    // next empty position
    int position;
    int totalCount;
    RationalNumber sum;
};

void rncInit(RationalNumberCollection *);

void rncAdd(RationalNumberCollection *, RationalNumber);

void rncRemove(RationalNumberCollection *, RationalNumber);

int rncCount(RationalNumberCollection *, RationalNumber);

int rncTotalUniqueCount(RationalNumberCollection *);

int rncTotalCount(RationalNumberCollection *);

RationalNumber rncSum(RationalNumberCollection *);

RationalNumber rncAverage(RationalNumberCollection *);

#endif // RATIONALNUMBERCOLLECTION_H
