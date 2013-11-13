#include "map.h"
#include "rationalnumber.h"
#include <cstring>
#include <iostream>
#include "keyvaluenode.h"

using namespace std;
using namespace rn::internal;

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
        delete root;
        cout << "Destroying map" << endl;
    }

    Map& Map::operator=(const Map& rhs) {

        cout << "Invoking =" << endl;

        if (this == &rhs) {
            return *this;
        }

        if(root) {
            delete root;
        }

        root = rhs.root;
        return *this;
    }

    bool Map::contains(const Map::key_type& key) const {
        cout << "Invoking contains" << endl;
        if(root == 0) {
            return false;
        } else {
            return root->find(key);
        }
    }

    Map::mapped_type& Map::operator[](const key_type& other) {
        if(root == 0) {
            root = new KeyValueNode(other, 2);
        }

        return root->find(other)->value();
    }


}
