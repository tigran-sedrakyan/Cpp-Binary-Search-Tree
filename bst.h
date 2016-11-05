#ifndef BST_INCLUDED
#define BST_INCLUDED
#include "node.h"

template <class T>
class BinSearchTree {
    private:
    node<T>* m_root;
    node<T>* insertHelper(T, node<T>*);
    node<T>* removeHelper(T, node<T>*);
    void preOrderHelper(node<T>*);
    void postOrderHelper(node<T>*);
    void inOrderHelper(node<T>*);
    bool searchHelper(T, node<T>*);
    int getHeightHelper(int, node<T>*);
    void inOrderFromLeft(node<T>*);
    void postOrderToRight(node<T>*);
    public:
    node<T>* findMin (node<T>*);
    node<T>* getRoot();
    //void set_root(node<T>*);
    BinSearchTree();
    void preOrder();
    void postOrder();
    void inOrder();
    void insert(T);
    bool search(T);
    void remove(T);
    int getHeight();
    void topView();
    ~BinSearchTree();
};


#endif // BST_INCLUDED
