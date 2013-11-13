#ifndef MAP_H
#define MAP_H

#include "rationalnumber.h"

namespace rn {

    class KeyValueNode;

    class Map
    {
        public:
            typedef RationalNumber key_type;
            typedef int mapped_type;

            Map();
            Map(const Map& rhs);
            ~Map();

            bool contains(const key_type& key) const;

            Map& operator=(const Map& rhs) const;
            mapped_type& operator[](const key_type& other) const;


        private:
            KeyValueNode* root;
    };

}

#endif // MAP_H
