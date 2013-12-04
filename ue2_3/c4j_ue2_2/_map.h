#ifndef _MAP_H
#define _MAP_H

#include <iostream>

template<class KeyT, class T>
class Map {
    public:
        typedef KeyT key_type;
        typedef T mapped_type;
        Map();
        Map(const Map<key_type, mapped_type> &rhs);
        ~Map();
        Map<key_type, mapped_type>& operator=(const Map<key_type, mapped_type>& rhs);
        mapped_type& operator[](const key_type& key);
        bool contains(const key_type& key) const;
    private:
        class KeyValueNode {
            public:
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

        KeyValueNode* root;
};

template<class KeyT, class T>
Map<KeyT, T>::Map()
    : root(0)
{
    std::cout << "Invoking map default constructor." << std::endl;
}

template<class KeyT, class T>
Map<KeyT, T>::Map(const Map<key_type, mapped_type>& rhs)
    : root(0)
{
    *this = rhs;
    std::cout << "Invoking map copy constructor." << std::endl;
}

template<class KeyT, class T>
Map<KeyT, T>::~Map()
{
    if(root) {
        delete root;
    }
    std::cout << "Destroying map" << std::endl;
}

template<class KeyT, class T>
Map<KeyT, T>& Map<KeyT, T>::operator=(const Map<KeyT, T>& rhs) {
    if (this == &rhs) {
        return *this;
    }

    if(root) {
        delete root;
    }

    root = rhs.root->clone();
    return *this;
}

template<class KeyT, class T>
T& Map<KeyT, T>::operator[](const KeyT& other) {
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

template<class KeyT, class T>
bool Map<KeyT, T>::contains(const KeyT& key) const {
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

template<class KeyT, class T>
Map<KeyT, T>::KeyValueNode::KeyValueNode(const KeyT& key, const T& value)
                : m_key(key), m_value(value), m_left(0), m_right(0)
{
                std::cout << "Creating new keyvaluenode." << std::endl;
}

template<class KeyT, class T>
Map<KeyT, T>::KeyValueNode::~KeyValueNode()
{
    std::cout << "Destroying keyvaluenode." << std::endl;
    delete m_left;
    delete m_right;
}

template<class KeyT, class T>
typename Map<KeyT, T>::KeyValueNode::KeyValueNode* Map<KeyT, T>::KeyValueNode::KeyValueNode::find(const KeyT& key)  {
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

template<class KeyT, class T>
void Map<KeyT, T>::KeyValueNode::KeyValueNode::insert(const KeyT& key, const T& type) {
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

template<class KeyT, class T>
typename Map<KeyT, T>::KeyValueNode* Map<KeyT, T>::KeyValueNode::KeyValueNode::clone() const {
    KeyValueNode* theClone = new KeyValueNode(m_key, m_value);

    if(m_left != 0) {
        theClone->m_left = m_left->clone();
    }

    if(m_right != 0) {
        theClone->m_right = m_right->clone();
    }
    return theClone;
}

#endif // _MAP_H
