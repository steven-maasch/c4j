#include "keyvaluenode.h"
#include <iostream>

namespace rn {

namespace internal {

            KeyValueNode::KeyValueNode(const key_type& key, const mapped_type& value)
                : key(key), value(value)
            {
            }

            KeyValueNode::~KeyValueNode()
            {

            }

            KeyValueNode* KeyValueNode::find(const key_type& key) {
                std::cout << "find" << std::endl;
                return 0;
            }

            void KeyValueNode::insert(const key_type& key, const mapped_type& type) {

            }

            KeyValueNode* KeyValueNode::clone() {

            }
}

}

