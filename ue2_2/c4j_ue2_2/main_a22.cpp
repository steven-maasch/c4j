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

    Map m1;
    Map m2;

    assert(!m1.contains(rn1));
    assert(!m2.contains(rn2));

    m1[rn1];
    assert(m1.contains(rn1));
    assert(!m2.contains(rn1));

    m1[rn1] = 4;
    m1[rn1] = 4;

    m1[rn2] = 5;
    assert(m1.contains(rn2));
    assert(m1[rn2] == 5);

    m1[rn1] = 6;
    assert(m1[rn1] == 6);

    Map m3(m1);
    assert(m3.contains(rn1));
    assert(m3.contains(rn2));

    m3[rn3] = 6;
    assert(!m1.contains(rn3));
    assert(!m2.contains(rn3));
    assert(m3.contains(rn3));
    assert(m3[rn3] == 6);


    cout << "main wird beendet." << endl;
    return 0;
}

