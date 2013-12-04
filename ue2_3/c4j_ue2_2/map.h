#ifndef MAP_H
#define MAP_H

#include "rationalnumber.h"
#include "keyvaluenode.h"

using namespace rn::internal;

namespace rn {

    class Map {
        public:
            typedef RationalNumber key_type;
            typedef int mapped_type;

            Map();
            Map(const Map& rhs);
            ~Map();

            Map& operator=(const Map& rhs);
            mapped_type& operator[](const key_type& other);
            bool contains(const key_type& key) const;

        private:
            KeyValueNode* root;
    };

}

#endif // MAP_H
