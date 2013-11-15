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
        cout << "Invoking map default constructor." << endl;
    }

    Map::Map(const Map& rhs)
        : root(0)
    {
       *this = rhs;
       cout << "Invoking map copy constructor." << endl;
    }

    Map::~Map()
    {
        delete root;
        cout << "Destroying map" << endl;
    }

    Map& Map::operator=(const Map& rhs) {


        if (this == &rhs) {
            return *this;
        }

        if(root) {
            delete root;
        }

        root = rhs.root->clone();

        return *this;
    }

    bool Map::contains(const Map::key_type& key) const {

        if(root == 0) {
            return false;
        } else {
            if(root->find(key)) {
                return true;
            } else {
                return false;
            }
        }
    }

    Map::mapped_type& Map::operator[](const key_type& other) {

        cout << "operator" << endl;
        if(root == 0) {
            root = new KeyValueNode(other, 0);
            return root->find(other)->value();
        } else {
            if(!contains(other)) {
                 root->insert(other, 0);
            }
        }
        return root->find(other)->value();
    }
}
