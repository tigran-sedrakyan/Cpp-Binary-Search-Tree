#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class node {
    public:
    T data;
    node<T>* left;
    node<T>* right;
    ~node(){
        delete left;
        delete right;
    }
};

#endif // NODE_H_INCLUDED
