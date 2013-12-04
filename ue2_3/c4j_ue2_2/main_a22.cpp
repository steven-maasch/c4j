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
    {
        Map<int, int> m9;
        m9[6] = 6;
        m9[3] = 3;
        m9[2] = 2;
        m9[4] = 4;
        m9[7] = 7;

        Map<int, int>::iterator i = m9.begin();
        cout << "kleinstes Element: " << i->first << "/"
        << i->second << endl;
        cout << "weitere Elemente, sortiert: " << endl;
        while(i!=m9.end()) {
        i++;
        pair<int, int> p = *i;
        cout << " " << p.first << "/"
        << p.second << endl;
        }
        m9.begin()->second = 2;
        //m9.begin()->first = 1;

    }



    cout << "main wird beendet." << endl;
    return 0;
}

