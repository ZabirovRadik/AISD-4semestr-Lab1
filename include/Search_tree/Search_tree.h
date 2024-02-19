#pragma once
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <random>
#include <complex>
#include <vector>

using namespace std;


template<typename Key>
class Set {
    struct Node {
        Key key;
        Node* right;
        Node* left;
        Node(const Key& key) {
            this->key = key;
            this->right = nullptr;
            this->left = nullptr;
        }
    };
    Node* _root;
    Node* copy(Node* root, Node* from) {
        if (!from) {
            root = nullptr;
            return root;
        }
        root = new Node(from->key);
        root->left = copy(root->left, from->left);
        root->right = copy(root->right, from->right);
        return root;
    }
    void delete_tree(Node* tmp) {
        if (tmp){
            delete_tree(tmp->left);
            delete_tree(tmp->right);
            delete tmp;
        }
    }
    void print(Node* tmp) {
        if (tmp) {
            print(tmp->left);
            print(tmp->right);
            cout << tmp->key << " ";
        }
    }
    void to_vector(Node* root, vector<Key>& result) {
        if (root == nullptr) {
            return;
        }
        to_vector(root->left, result);
        to_vector(root->right, result);
        result.push_back(root->key);
    }
public:
    Set(): _root(nullptr){}
    Set(const Set& Another) {
        _root = copy(_root, Another._root);
    }
    void operator=(const Set& Another) {
        _root = copy(_root, Another._root);
    }
    ~Set() {
        delete_tree(_root);
    }
    bool insert(const Key& key) {
        if (!_root) {
            _root = new Node(key);
            return true;
        }
        Node* tmp = _root;
        while (tmp){
            if (key < tmp->key && !tmp->left) {
                tmp->left = new Node(key);
                return true;
            }
            if (key == tmp->key)
                return false;
            if (key > tmp->key && !tmp->right) {
                tmp->right = new Node(key);
                return true;
            }
            if (tmp->key > key)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
    }
    void print() {
        print(_root);
        cout << endl;
    }
    bool contains(const Key& key) {
        Node* tmp = _root;
        while (tmp && tmp->key != key){
            if (tmp->key > key)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        return tmp;
    }
    bool erase(const Key& key) {
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur && cur->key != key) {
            parent = cur;
            if (key < cur->key) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        if (!cur)
            return false;
        if (parent && !cur->left) {
            if (parent->left == cur)
                parent->left = cur->right;
            if (parent->right == cur)
                parent->right = cur->right;
            delete cur;
            return true;
        }
        if (parent && !cur->right) {
            if (parent->left == cur)
                parent->left = cur->left;
            if (parent && parent->right == cur)
                parent->right = cur->left;
            delete cur;
            return true;
        }
        Node* tmp = cur->right;
        while (tmp->left)
            tmp = tmp->left;
        int tmp_val = tmp->key;
        erase(tmp_val);
        cur->key = tmp_val;
    }
    vector<Key> set_to_vector() {
        std::vector<int> result;
        to_vector(_root, result);
        return result;
    }
};

size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

template<typename Key>
vector<Key> without_repetitions(const vector<Key>& initial_vec) {
    Set<Key> Answer, Tmp;
    for (size_t i = 0; i < initial_vec.size(); ++i) {
        if (not Answer.insert(initial_vec[i]))
            Tmp.push_back(initial_vec[i]);
    }
    vector<Key> tmp_vec = Tmp.set_to_vector();
    for (size_t j = 0; j < tmp_vec.size(); ++j)
        Answer.erase(tmp_vec[j]);
    return Answer.set_to_vector();
}