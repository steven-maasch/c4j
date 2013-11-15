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
            KeyValueNode* clone() const;

            mapped_type& value() { return m_value; }


        private:
            key_type m_key;
            mapped_type m_value;
            KeyValueNode* m_left;
            KeyValueNode* m_right;

    };

}

}


#endif // KEYVALUENODE_H
