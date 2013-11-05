/*
 *
 * C / C++ für Java-Programmierer
 * Einfacher Test-Treiber für class RationalNumber
 * Autor: Hartmut Schirmacher
 *
 */

#include <iostream>
#include "assert.h"
#include "rationalnumber.h"

using namespace std;
using namespace rn;

void doUnitTests_RationalNumber() {

    cout << "Starting unit tests for class RationalNumber..." << endl;

    {
        // test default constructor, isValid(), and accessor num()
        cout << "- default constructor..." << flush;
        RationalNumber a;
        assert(a.isValid());
        assert(a.num() == 0);
        cout << " passed." << endl;
    }

    {
        // test non-default constructors and both accessors num() and denom()
        cout << "- more constructors..." << flush;
        RationalNumber a(1,2);
        assert(a.isValid());
        assert(a.num() == 1);
        assert(a.denom() == 2);

        // constructors with single argument: equivalent to integer
        RationalNumber b(0);
        assert(b.isValid());
        assert(b.num() == 0 && b.denom() == 1);

        RationalNumber c(7);
        assert(c.isValid());
        assert(c.num() == 7 && c.denom() == 1);

        cout << " passed." << endl;
    }

    {
        // test const RationalNumber objects, operator==(), normalization, and inverse()
        cout << "- const..." << flush;
        const RationalNumber a(6,4), b(3,2);
        assert(a.isValid());
        assert(b.isValid());
        assert(a == b);
        assert(a.inverse() == RationalNumber(2,3));

        cout << " passed." << endl;
    }

    {
        // addition and unary minus
        cout << "- operator+()..." << flush;
        const RationalNumber a(3,2), b(4,3), c(3*3+4*2,2*3);
        assert(a + b == c);
        assert(a + (-a) == RationalNumber(0));

        cout << " passed." << endl;
    }

    {
        // order
        cout << "- ordered sequence..." << flush;
        const RationalNumber a(2,3), b(3,4), c(-4,5);
        assert(a < b);
        assert(c < a);
        assert(c < b);
        assert(!(a < c));
        cout << " passed." << endl;
    }

    cout << "Unit tests for class RationalNumber finished!" << endl;

}

int main()
{
    doUnitTests_RationalNumber();
    return 0;
}

