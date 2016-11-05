#include <iostream>
#include "bst.cpp"
using namespace std;

int main()
{
    BinSearchTree<int> t;
    int root;
    cout << "Enter the value of the root of the tree: ";
    cin >> root;
    t.insert(root);
    cout << endl << "Note that I will print the tree in inorder traversal (increasing order), so it is easy to check if I'm doing everything correct :)" << endl << endl;
    int value;
    int op;
    while (op != -1) {
    cout << "Enter number of operation you want to perform: (enter -1 to exit and delete the tree)" << endl << endl;
    cout << "1.Insert" << endl;
    cout << "2.Remove" << endl;
    cout << "3.Search for an element" << endl;
    cout << "4.Get height of the tree" << endl;
    cout << "5.Inorder traversal" << endl;
    cout << "6.Preorder traversal" << endl;
    cout << "7.Postorder traversal" << endl;
    cout << "8.Top view of the tree" << endl;
    cout << "9.Value of the root of the tree" << endl << endl;
    cin >> op;
    cout << endl;
    switch (op) {
        case 1:
        {
        cout << "Enter value to be inserted: ";
        cin >> value;
        if (t.search(value) == 1) {
            cout << "No duplicate vertex allowed!" << endl;
        }
        else {
        t.insert(value);
        }
        cout << "The resulting tree is" << endl;
        t.inOrder();
        cout << endl;
        break;
        }
        case 2:
        {
        cout << "Enter value of the node to be removed: ";
        cin >> value;
        if (t.search(value) == 0) {
            cout << "The value was not found in the tree. Removal impossible!" << endl;
        }
        else {
            t.remove(value);
        }
        cout << "The resulting tree is";
        if (t.getHeight() < 0) {
            cout << " empty" << endl;
        }
        else {
            cout << endl;
        }
        t.inOrder();
        cout << endl;
        break;
        }
        case 3:
        {
        cout << "Enter value to be searched: ";
        cin >> value;
        if (t.search(value) == 0) {
            cout << "Search returned 0 (element not found)" << endl;
        }
        else {
            cout << "Search returned 1 (element found)" << endl;
        }
        break;
        }
        case 4:
        cout << "The height of the tree is " << t.getHeight();
        if (t.getHeight() < 0) {
            cout << " (the tree is empty)" << endl;
        }
        else {
            cout << endl;
        }
        break;
        case 5:
        cout << "Printing the inorder traversal:" << endl;
        t.inOrder();
        cout << endl;
        break;
        case 6:
        cout << "Printing the preorder traversal:" << endl;
        t.preOrder();
        cout << endl;
        break;
        case 7:
        cout << "Printing the postorder traversal:" << endl;
        t.postOrder();
        cout << endl;
        break;
        case 8:
        if (t.getHeight() < 0) {
            cout << "The tree is empty. Top view doesn't exist! (hint: insert some data)" << endl;
        }
        else {
        cout << "Top view is" << endl;
        t.topView();
        }
        cout << endl;
        break;
        case 9:
        if (t.getHeight() < 0) {
            cout << "The tree is empty. Root doesn't exist! (hint: insert some data)" << endl;
        }
        else {
        cout << "The value of the root is: " << t.getRoot()->data << endl;
        }
        break;
        case -1:
        break;
        default:
            cout << "Operation number not valid! Try again!";
            break;
    }
    cout << endl;
    }
}
