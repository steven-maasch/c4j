#include "keyvaluenode.h"
#include <iostream>

using namespace std;

namespace rn {

namespace internal {

            KeyValueNode::KeyValueNode(const key_type& key, const mapped_type& value)
                : m_key(key), m_value(value), m_left(0), m_right(0)
            {
                cout << "Creating new keyvaluenode." << endl;
            }

            KeyValueNode::~KeyValueNode()
            {
                cout << "Destroying keyvaluenode." << endl;
                delete m_left;
                delete m_right;
            }

            KeyValueNode* KeyValueNode::find(const key_type& key)  {

                if(m_key == key) {
                    return this;
                }

                if(key < m_key && m_left != 0) {
                    return m_left->find(key);
                }

                if(m_key < key && m_right != 0) {
                    return m_right->find(key);
                }

                return 0;
            }

            void KeyValueNode::insert(const key_type& key, const mapped_type& type) {

                if(m_key == key) {
                    m_value = type;
                    return;
                }

                if(key < m_key) {
                    if(m_left == 0) {
                        m_left = new KeyValueNode(key, type);
                        return;
                    } else {
                        m_left->insert(key, type);
                        return;
                    }
                } else {
                    if(m_right == 0) {
                        m_right = new KeyValueNode(key, type);
                        return;
                    } else {
                        m_right->insert(key, type);
                        return;
                    }
                }
            }

            KeyValueNode* KeyValueNode::clone() const {

                KeyValueNode* theClone = new KeyValueNode(m_key, m_value);

                if(m_left != 0) {
                    theClone->m_left = m_left->clone();
                }

                if(m_right != 0) {
                    theClone->m_right = m_right->clone();
                }

                return theClone;
            }
}

}

