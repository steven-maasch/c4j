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
#include "map.h"

using namespace std;
using namespace rn;

int main()
{
    cout << "main wird begonnen." << endl;
    Map m;
    Map m2;
    m2 = m;
    cout << "main wird beendet." << endl;
    return 0;
}

