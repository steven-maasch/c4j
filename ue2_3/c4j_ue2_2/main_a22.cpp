/*
 *
 *
 *
 */

#include <iostream>
#include "assert.h"
#include "rationalnumber.h"
#include "map.t"

using namespace std;

int main()
{
    cout << "main wird begonnen." << endl;

    Map<int, int> m;
    m[6] = 6;
    m[3] = 3;
    m[2] = 2;
    m[4] = 4;
    m[7] = 7;
    m[20] = 20;
    m[25] = 25;
    m[24] = 24;
    m[21] = 21;
    m[18] = 18;

    Map<int, int>::iterator i = m.begin();
    for(i = m.begin(); i != m.end(); i++) {
        cout << i->first << " => " << i->second << endl;
    }

    //m.begin()->first = 1;

    Map<int, string> m1;
    m1[1] = "spam";
    m1[8] = "ham";
    m1[6] = "eggs";
    m1[7] = "foo";
    m1[12] = "bar";
    m1[-4] = "eggs";

    Map<int, string>::iterator i1 = m1.begin();
    for(i1 = m1.begin(); i1 != m1.end(); i1++) {
        cout << i1->first << " => " << i1->second << endl;
    }

    Map<int, string>::iterator i2 = m1.begin();
    assert(i2->first == -4);
    assert(i2++->first == -4);
    assert(i2->first == 1);

    cout << "main wird beendet." << endl;
    return 0;
}
