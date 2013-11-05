#include "rationalnumbercollection.h"
#include <stdlib.h>

struct RationalNumberCollectionComponent {
    RationalNumber r;
    int counter;
};

struct RationalNumberCollection {
    RationalNumberCollectionComponent *collection;
    // next empty position
    int position;
    int totalCount;
    int capacity;
    RationalNumber sum;
};

void rncInit(RationalNumberCollection*, RationalNumberCollectionComponent*, int);
int rncBinarySerach(RationalNumberCollection *, RationalNumber, int, int);
int rncContains(RationalNumberCollection *, RationalNumber);


RationalNumberCollection *rncCreate(int n){
    RationalNumberCollectionComponent* tmp = (RationalNumberCollectionComponent*) malloc(sizeof(RationalNumberCollectionComponent) * n);
    RationalNumberCollection* rnc = (RationalNumberCollection*) malloc(sizeof(RationalNumberCollection));
    rncInit(rnc, tmp, n);

    return rnc;
}

void rncDelete(RationalNumberCollection *rnc){
    free(rnc->collection);
    free(rnc);
}

void rncInit(RationalNumberCollection *rnc, RationalNumberCollectionComponent* collection, int capacity) {
    rnc->position = 0;
    rnc->totalCount = 0;
    rnc->collection = collection;
    rnc->capacity = capacity;

    RationalNumber initalSum = { 0, 1 };
    rnc->sum = initalSum;

}

void rncAdd(RationalNumberCollection * rnc, RationalNumber rn) {

    int index = rncContains(rnc, rn);

    if(index > -1) {
        rnc->collection[index].counter++;
    } else {
        if(rnc->capacity == rnc->totalCount){
            RationalNumberCollectionComponent* tmp = (RationalNumberCollectionComponent*) malloc(sizeof(RationalNumberCollectionComponent) * (rnc->capacity + 20));
            for(int i = 0; i<rnc->capacity; i++){
                tmp[i] = rnc->collection[i];
            }
            free(rnc->collection);
            rnc->collection = tmp;
            rnc->capacity += 20;
        }

        int insertPos = 0;

        while(rnLessThan(rnc->collection[insertPos].r, rn) && insertPos < rnc->position) {
            insertPos++;
        }

        // Verschieben
        for (int i = insertPos+1; i < rnc->position+1; i++) {
            rnc->collection[i] = rnc->collection[i-1];
        }

        RationalNumberCollectionComponent tmp = { rn, 1};
        rnc->collection[insertPos] = tmp;
        rnc->position++;
    }

    rnc->totalCount++;
    rnc->sum = rnAdd(rnc->sum, rn);

}

int rncCount(RationalNumberCollection * rnc, RationalNumber rn) {

        int index = rncContains(rnc, rn);

        if(index > -1) {
            return rnc->collection[index].counter;
        } else {
            return 0;
        }
}

void rncRemove(RationalNumberCollection * rnc, RationalNumber rn) {
    int index = rncContains(rnc, rn);

    // rn not in collection
    if(index < 0) {
        return;
    }

    if(rnc->collection[index].counter == 1) {
        for(int i = index; i < rnc->position; i++) {
            rnc->collection[i] = rnc->collection[i+1];
        }
        rnc->position--;
    } else {
        rnc->collection[index].counter--;
    }
    rnc->totalCount--;
    rnc->sum = rnSubtract(rnc->sum, rn);

}

int rncTotalUniqueCount(RationalNumberCollection * rnc) {
    return rnc->position;
}

int rncTotalCount(RationalNumberCollection * rnc) {
    return rnc->totalCount;
}

RationalNumber rncSum(RationalNumberCollection * rnc) {
    return rnc->sum;
}

RationalNumber rncAverage(RationalNumberCollection * rnc) {
    RationalNumber totalCountAsRN = { rnc->totalCount, 1 };
    RationalNumber average = rnDivide(rnc->sum, totalCountAsRN);
    return average;
}

int rncContains(RationalNumberCollection * rnc, RationalNumber rn) {
    int left = 0;
    int right = rnc->position - 1;
    return rncBinarySerach(rnc, rn, left, right);
}

int rncBinarySerach(RationalNumberCollection * rnc, RationalNumber rn, int left, int right) {

    if(left > right) {
        return -1;
    }

    int middle = (left + right) / 2;

    if(rnEqual(rn, rnc->collection[middle].r)) {
        return middle;
    }

    if(rnLessThan(rn, rnc->collection[middle].r)) {
        return rncBinarySerach(rnc, rn, left, middle - 1);
    } else {
        return rncBinarySerach(rnc, rn, middle + 1, right);
    }

}

int rncGetCapacity(RationalNumberCollection *rnc){
    return rnc->capacity;
}
