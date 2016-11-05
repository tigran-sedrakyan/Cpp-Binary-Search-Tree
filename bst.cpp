#include "bst.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
BinSearchTree<T>::BinSearchTree() {
    m_root = nullptr;
}

template <class T>
node<T>* BinSearchTree<T>::getRoot() {
    return m_root;
}
/*
void BinSearchTree::set_root(node<T>* r) {
    m_root = r;
}*/

template <class T>
void BinSearchTree<T>::preOrderHelper(node<T>* root) {
    if (root!=nullptr) {
        cout << root->data << " ";
        preOrderHelper(root->left);
        preOrderHelper(root->right);
    }
}

template <class T>
void BinSearchTree<T>::preOrder() {
    preOrderHelper(m_root);
}

template <class T>
void BinSearchTree<T>::postOrderHelper(node<T>* root){
    if(root != NULL) {
            postOrderHelper(root->left);
            postOrderHelper(root->right);
            cout << root->data << " ";
    }
}

template <class T>
void BinSearchTree<T>::postOrder() {
    postOrderHelper(m_root);
}

template <class T>
void BinSearchTree<T>::inOrderHelper(node<T>* root) {
    if (root!=nullptr) {
        inOrderHelper(root->left);
        cout << root->data << " ";
        inOrderHelper(root->right);
    }
}

template <class T>
void BinSearchTree<T>::inOrder() {
    inOrderHelper(m_root);
}

template <class T>
node<T>* BinSearchTree<T>::insertHelper(T value, node<T>* r)
{
   if (r == nullptr) {
       node<T>* temp = new node<T>;
       temp->data = value;
       temp->left = nullptr;
       temp->right = nullptr;
       return temp;
   }
    if (value < r->data) {
        r->left = insertHelper(value, r->left);
    }
    else if (value > r->data) {
        r->right = insertHelper(value, r->right);
    }
    return r;
}

template <class T>
void BinSearchTree<T>::insert(T value) {
    m_root = insertHelper(value, m_root);
}

template <class T>
bool BinSearchTree<T>::searchHelper(T value, node<T>* r) {
    if (r == nullptr || value == r->data) {
        return r;
    }
    else if (value < r->data) {
        return searchHelper(value, r->left);
    }
    else if (value > r->data) {
        return searchHelper (value, r->right);
    }
}

template <class T>
bool BinSearchTree<T>::search(T value) {
    return searchHelper(value, m_root);
}

template <class T>
node<T>* BinSearchTree<T>::removeHelper(T data, node<T>* r) {
    if (r == nullptr) {
        return r;
    }
    else if (data < r->data) {
        r->left = removeHelper(data, r->left);
    }
    else if (data > r->data) {
        r->right = removeHelper(data, r->right);
    }
    else if (data == r->data){
        if (r->left == nullptr && r->right == nullptr) {
            r = nullptr;
            delete r;
        }
        else if (r->left == nullptr) {
            node<T>* temp = r;
            r = r->right;
            temp = nullptr;
            delete temp;
        }
        else if (r->right == nullptr) {
            node<T>* temp = r;
            r = r->left;
            temp = nullptr;
            delete temp;
        }
        else {
            node<T>* temp = findMin(r->right);
            r->data = temp->data;
            r->right = removeHelper(temp->data, r->right);
        }
    }
    return r;
}

template <class T>
void BinSearchTree<T>::remove(T value) {
    m_root = removeHelper(value, m_root);
}

template <class T>
node<T>* BinSearchTree<T>::findMin (node<T>* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

template <class T>
int BinSearchTree<T>::getHeightHelper(int i, node<T>* root) {
        i++;
        int r;
        int l;
        if(root != nullptr){
            l = getHeightHelper(i, root->left);
            r = getHeightHelper(i, root->right);
        }
        else {
            return i-2;
        }
        if (r>l) {
            return r;
        }
        else {
            return l;
        }
}

template <class T>
int BinSearchTree<T>::getHeight() {
    return getHeightHelper(0, m_root);
}

template <class T>
void BinSearchTree<T>::inOrderFromLeft(node<T>* root) {
    if (root != nullptr){
        inOrderFromLeft(root->left);
        cout << root->data << " ";
    }
}

template <class T>
void BinSearchTree<T>::postOrderToRight(node<T>* root) {
    if (root!=nullptr) {
        cout << root->data << " ";
        postOrderToRight(root->right);
    }
}

template <class T>
void BinSearchTree<T>::topView()
{
    inOrderFromLeft(m_root);
    postOrderToRight(m_root->right);
}

template <class T>
BinSearchTree<T>::~BinSearchTree()
{
   cout << "Deleting the tree" << endl;
   delete m_root;
}
