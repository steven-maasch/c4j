#include <stdio.h>
#include <assert.h>

#include "rationalnumber.h"
#include "rationalnumbercollection.h"


int main(void)
{

    printf("Performing unit tests for RationalNumber...\n");

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );

    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( !rnIsValid(t4) );

    // MyTests
    RationalNumber n30 = { 1, 2 },
                   n31 = { 1, -3 },
                   n32 = { -1, -4 },
                   n33 = { -1, -2 };


    assert(rnLessThan(n31, n30));
    assert(rnLessThan(n32, n33));

    printf(" successful!\n");

    printf("Performing unit tests for RationalNumberCollection...\n");

    /* Part 2 - RationalNumberCollection */

    RationalNumber myN1 = { 1, 2 },
                   myN2 = { 1, 3 },
                   myN3 = { 1, 4 },
                   myN4 = { 1, -4 },
                   myN5 = { 1, -2 };

    RationalNumberCollection *c = rncCreate(2);

    assert(!rnIsValid(rncAverage(c)));

    rncAdd(c, myN1);
    assert(rncCount(c, myN1) == 1);
    assert(rncCount(c, myN2) == 0);

    rncAdd(c, myN1);
    assert(rncCount(c, myN1) == 2);
    assert(rncTotalCount(c) == 2);
    assert(rncTotalUniqueCount(c) == 1);
    assert(rnEqual(rncAverage(c), myN1));

    rncAdd(c, myN2);
    rncAdd(c, myN3);
    assert(rncGetCapacity(c) == 22);
    rncAdd(c, myN4);
    assert(rncTotalUniqueCount(c) == 4);

    RationalNumber ccc = { -4, -3 };
    assert(rnEqual(rncSum(c), ccc));

    rncAdd(c, myN5);
    rncAdd(c, myN5);
    rncRemove(c, myN5);

    assert(rncCount(c, myN5) == 1);
    RationalNumber ccc1 = { 5, 6 };
    assert(rnEqual(rncSum(c), ccc1));

    RationalNumber ccc2 = { 5, 36};
    assert(rnEqual(rncAverage(c), ccc2));

    rncDelete(c);

    printf(" successful!\n");

    return 0;
}

