/*
 *
 *
 *
 */

#include <iostream>
#include "assert.h"
#include "rationalnumber.h"
#include "map.h"
#include "_map.h"

using namespace std;

int main()
{
    cout << "main wird begonnen." << endl;

    rn::RationalNumber rn1(1,2);
    rn::RationalNumber rn2(1,4);
    rn::RationalNumber rn3(1,8);

    {
        // Checking default-constructor.

        rn::Map m1, m2;

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

        rn::Map m3;
        m3[rn3];

        m3 = m1;
        assert(!m3.contains(rn3));
        assert(m3.contains(rn1));
        assert(m3.contains(rn2));

        // Checking copy-constructor.

        rn::Map m4(m1);
        assert(m4.contains(rn1));
        assert(m4.contains(rn2));

        m4[rn3] = 6;
        assert(m4.contains(rn3));
        assert(m4[rn3] == 6);
        assert(!m1.contains(rn3));
        assert(!m2.contains(rn3));

    }

    /*
     *  Testin template with RationalNumber, int
     */

    {

        Map<rn::RationalNumber, int> m1, m2;

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

        Map<rn::RationalNumber, int> m3;
        m3[rn3];

        m3 = m1;
        assert(!m3.contains(rn3));
        assert(m3.contains(rn1));
        assert(m3.contains(rn2));

        // Checking copy-constructor.

        Map<rn::RationalNumber, int> m4(m1);
        assert(m4.contains(rn1));
        assert(m4.contains(rn2));

        m4[rn3] = 6;
        assert(m4.contains(rn3));
        assert(m4[rn3] == 6);
        assert(!m1.contains(rn3));
        assert(!m2.contains(rn3));

    }

    cout << "main wird beendet." << endl;
    return 0;
}

