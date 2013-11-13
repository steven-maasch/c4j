#ifndef KEYVALUENODE_H
#define KEYVALUENODE_H

namespace rn {

namespace internal {

    class KeyValueNode {
        public:
            typedef RationalNumber key_type;
            typedef int mapped_type;

            KeyValueNode(const key_type& key, const mapped_type& value)
                : key(key), value(value)
            {
            }

            ~KeyValueNode()
            {

            }

            KeyValueNode* find(const key_type& key) {
                if(key == this->getKey()) {
                    return this;
                } else if(key < this->getKey()) {
                    return this->find(this->getLeft()->getKey());
                } else if(this->getKey() < key) {
                    return this->find(this->getRight()->getKey());
                } else {
                    return 0;
                }
            }

            void insert(const key_type& key, const mapped_type& type) {

            }

            KeyValueNode* clone() {

            }

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
