#ifndef KEYVALUENODE_H
#define KEYVALUENODE_H

#include "rationalnumber.h"

namespace rn {

namespace internal {

    class KeyValueNode {
        public:
            typedef RationalNumber key_type;
            typedef int mapped_type;

            KeyValueNode(const key_type& key, const mapped_type& value);
            ~KeyValueNode();


            KeyValueNode* find(const key_type& key);
            void insert(const key_type& key, const mapped_type& type);
            KeyValueNode* clone();

            key_type getKey() const { return key; }
            mapped_type getValue() const { return value; }
            KeyValueNode* getLeft() const { return left; }
            KeyValueNode* getRight() const { return right; }


        private:
            key_type key;
            mapped_type value;
            KeyValueNode* left;
            KeyValueNode* right;

    };

}

}


#endif // KEYVALUENODE_H
