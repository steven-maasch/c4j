/*
 *
 *
 *
 */

#include <iostream>
#include "assert.h"
#include "rationalnumber.h"
#include "map.h"

using namespace std;
using namespace rn;

int main()
{
    cout << "main wird begonnen." << endl;

    RationalNumber rn1(1,2);
    RationalNumber rn2(1,4);
    RationalNumber rn3(1,8);

    // Checking default-constructor.

    Map m1;
    Map m2;

    // Checking contains

    assert(!m1.contains(rn1));
    assert(!m2.contains(rn2));

    // Checking [] operator.

    m1[rn1];
    assert(m1.contains(rn1));
    assert(!m2.contains(rn1));
    assert(m1[rn1] == 0);

    m1[rn2] = 5;
    assert(m1.contains(rn2));
    assert(m1[rn2] == 5);

    m1[rn1] = 4;
    m1[rn1] = 8;
    m1[rn1] = 6;
    assert(m1[rn1] == 6);

    // Checking = operator

    Map m4;
    m4[rn3];

    m4 = m1;
    assert(!m4.contains(rn3));
    assert(m4.contains(rn1));
    assert(m4.contains(rn2));

    // Checking copy-constructor.

    Map m3(m1);
    assert(m3.contains(rn1));
    assert(m3.contains(rn2));

    m3[rn3] = 6;
    assert(m3.contains(rn3));
    assert(m3[rn3] == 6);
    assert(!m1.contains(rn3));
    assert(!m2.contains(rn3));

    cout << "main wird beendet." << endl;
    return 0;
}

