#ifndef _MAP_H
#define _MAP_H

#include <iostream>
#include "rationalnumber.h"
#include "keyvaluenode.h"

template<class KeyT, class T>
class Map {
    public:
        typedef KeyT key_type;
        typedef T mapped_type;

        Map()
            : root(0)
        {
            std::cout << "Invoking map default constructor." << std::endl;
        }

        Map(const Map<KeyT, T>& rhs)
            : root(0)
        {
            *this = rhs;
            std::cout << "Invoking map copy constructor." << std::endl;
        }

        ~Map()
        {
            if(root) {
                delete root;
            }
            std::cout << "Destroying map" << std::endl;
        }

        Map<KeyT, T>& operator=(const Map<KeyT, T>& rhs) {
            if (this == &rhs) {
                return *this;
            }

            if(root) {
                delete root;
            }

            root = rhs.root->clone();

            return *this;
        }

        mapped_type& operator[](const key_type& other) {
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

        bool contains(const key_type& key) const {
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

    private:
        typename rn::internal::KeyValueNode* root;
};
#endif // _MAP_H
