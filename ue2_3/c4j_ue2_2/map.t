#ifndef MAP_T
#define MAP_T

#include <iostream>

template<class KeyT, class T>
class Map {
    public:
        typedef KeyT key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_t;
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
                mapped_type& value() { return m_pair.second; }
                value_t& pair() { return m_pair; }
                KeyValueNode* left() { return m_left; }
                KeyValueNode* right() { return m_right; }
            private:
                value_t m_pair;
                KeyValueNode* m_left;
                KeyValueNode* m_right;
        };

        KeyValueNode* root;

    public:
        class Iterator {
            public:
                Iterator(Map<KeyT, T>* parent, KeyValueNode* node=0)
                    : m_parent(parent), m_node(node)
                {

                }

                bool operator==(const Iterator& rhs) const {
                    return m_node == rhs.m_node;
                }

                bool operator !=(const Iterator& rhs) const {
                    return m_node != rhs.m_node;
                }

                value_t& operator*() {
                    return m_node->pair();
                }

                value_t* operator->() {
                    return &(m_node->pair());
                }

                Iterator& operator++() {
                    if(m_node == 0) {
                        return *this;
                    }

                    if(m_node->right() != 0) {
                        m_node = m_node->right();
                        while(m_node->left()) {
                            m_node = m_node->left();
                        }
                        return *this;
                    }

                    KeyValueNode* next = 0;
                    KeyValueNode* from = m_node;
                    KeyValueNode* root = m_parent->root;
                    while(root != 0) {
                        if(from->pair().first < root->pair().first) {
                            next = root;
                            root = root->left();
                        } else if(from->pair().first > root->pair().first) {
                            root = root->right();
                        } else {
                            break;
                        }
                    }
                    m_node = next;
                    return *this;
                }

                Iterator operator++(int) {
                    if(m_node == 0) {
                        return *this; // Richtig
                    }

                    KeyValueNode* oldValue = m_node;
                    if(m_node->right() != 0) {
                        m_node = m_node->right();
                        while(m_node->left()) {
                            m_node = m_node->left();
                        }
                        return Iterator(m_parent, oldValue);
                    }

                    KeyValueNode* next = 0;
                    KeyValueNode* from = m_node;
                    KeyValueNode* root = m_parent->root;
                    while(root != 0) {
                        if(from->pair().first < root->pair().first) {
                            next = root;
                            root = root->left();
                        } else if(from->pair().first > root->pair().first) {
                            root = root->right();
                        } else {
                            break;
                        }
                    }
                    m_node = next;
                    return Iterator(m_parent, from);
                }

            private:
                Map<KeyT, T>* m_parent;
                KeyValueNode* m_node;


        };

        typedef Map::Iterator iterator;
        iterator begin();
        iterator end();
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
        root = new KeyValueNode(other, T());
        return root->find(other)->value();
    } else {
        if(!contains(other)) {
            root->insert(other, T());
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
typename Map<KeyT, T>::iterator Map<KeyT, T>::begin() {
    if(!root) {
        return iterator(this);
    }

    KeyValueNode* now = root;
    while(now->left()) {
        now = now->left();
    }
    return iterator(this, now);
}

template<class KeyT, class T>
typename Map<KeyT, T>::iterator Map<KeyT, T>::end() {
    return Map<KeyT, T>::iterator(this);
}

template<class KeyT, class T>
Map<KeyT, T>::KeyValueNode::KeyValueNode(const KeyT& key, const T& value)
    : m_pair(key, value), m_left(0), m_right(0)
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
    if(m_pair.first == key) {
        return this;
    }

    if(key < m_pair.first && m_left != 0) {
        return m_left->find(key);
    }

    if(m_pair.first < key && m_right != 0) {
        return m_right->find(key);
    }
    return 0;
}

template<class KeyT, class T>
void Map<KeyT, T>::KeyValueNode::KeyValueNode::insert(const KeyT& key, const T& type) {
    if(m_pair.first == key) {
        m_pair.second = type;
    return;
    }

    if(key < m_pair.first) {
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
    KeyValueNode* theClone = new KeyValueNode(m_pair.first, m_pair.second);

    if(m_left != 0) {
        theClone->m_left = m_left->clone();
    }

    if(m_right != 0) {
        theClone->m_right = m_right->clone();
    }
    return theClone;
}

#endif // MAP_T
