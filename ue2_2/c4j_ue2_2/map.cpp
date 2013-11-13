#include "Map.h"
#include "rationalnumber.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace rn {

    Map::Map()
        : root(0)
    {
        cout << "Creating new map" << endl;
    }

    Map::Map(const Map& rhs)
        : root(0)
    {
       memcpy(root, rhs.root, sizeof(rhs));
    }

    Map::~Map()
    {
        cout << "Destroying map" << endl;
    }

    bool Map::contains(const Map::key_type& key) const {
        return false;
    }

    class KeyValueNode {
        public:
            typedef RationalNumber key_type;
            typedef int mapped_type;

            KeyValueNode(const key_type& key, const mapped_type& value)
                : key(key), value(value)
            {
            }

            ~KeyValueNode()
            {

            }

            KeyValueNode* find(const key_type& key)
            {
                return 0;
            }

            void insert(const key_type& key, const mapped_type& type)
            {

            }

            KeyValueNode* clone()
            {

            }

        private:
            key_type key;
            mapped_type value;
            KeyValueNode* left;
            KeyValueNode* right;

    };

}
