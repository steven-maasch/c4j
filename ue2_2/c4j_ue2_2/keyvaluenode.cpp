#include "keyvaluenode.h"
#include <iostream>

namespace rn {

namespace internal {

            KeyValueNode::KeyValueNode(const key_type& key, const mapped_type& value)
                : m_key(key), m_value(value), m_left(0), m_right(0)
            {
            }

            KeyValueNode::~KeyValueNode()
            {
                delete m_left;
                delete m_right;
            }

            KeyValueNode* KeyValueNode::find(const key_type& key) {
                std::cout << "find" << std::endl;
                if(m_key == key) {
                    return this;
                }

                if(key < m_key) {
                    return m_left->find(key);
                }

                if(m_key < key) {
                    return m_right->find(key);
                }

                return 0;
            }

            void KeyValueNode::insert(const key_type& key, const mapped_type& type) {



            }

            KeyValueNode* KeyValueNode::clone() {

            }
}

}

