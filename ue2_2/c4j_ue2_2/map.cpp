#include "map.h"
#include "rationalnumber.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace rn {

    Map::Map()
        : root(0)
    {
        cout << "Invoking default constructor." << endl;
    }

    Map::Map(const Map& rhs)
        : root(0)
    {
       *this = rhs;
       cout << "Invoking copy constructor." << endl;
    }

    Map::~Map()
    {
        cout << "Destroying map" << endl;
    }

    Map& Map::operator=(const Map& rhs) {
        cout << "Invoking =" << endl;
        memcpy(root, rhs.root, sizeof(rhs));
        return *this;
    }

    bool Map::contains(const Map::key_type& key) const {
        return root->find(key);
    }

    const Map::mapped_type& Map::operator[](const Map::key_type& other) const {

    }

    Map::mapped_type& Map::operator[](const Map::key_type& other) {

    }

}
