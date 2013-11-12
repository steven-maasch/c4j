#include "rationalnumber.h"

#ifndef MAP_H
#define MAP_H

namespace rn {

    class Map {

    public:
        typedef RationalNumber key_type;
        typedef int mapped_type;

        Map();
        Map(const Map& rhs);
        ~Map();

        Map& operator=(const Map& rhs) const;
        mapped_type& operator[](const key_type& other) const;
        bool contains(const key_type& key) const;

    private:
        key_type key;
        mapped_type value;

        class KeyValueNode {

        public:
            KeyValueNode(const key_type& key, const mapped_type& value)
                : key(key), value(value)
            {

            }

            ~KeyValueNode() {

            }

            KeyValueNode& find(const key_type& key) const {

            }


        private:
            key_type key;
            mapped_type value;
        };
    };

}

#endif // MAP_H
