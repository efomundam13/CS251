/*
Programmer: Manny Fomundam
Date: November 13, 2022
Implement a Binary Search Tree for integers which uses Lazy Deletion
*/

#ifndef BST_H
#define BST.H

#include <iostream>
#include <stdexcept>

using namespace std;

class LazyBST
{
    public:
        //Constructor
        LazyBST();
        //Destructor
        ~LazyBST();

        //Puts a node in the tree.
        void insert(int x);
        //Deletes a node in the tree.
        void remove(int x);
        //Checks for a node in the tree.
        bool contain(int x) const;
        
//Private struct representing a Binary Search Tree Node
private:
    struct Node;
    //Parent node
    Node* root;

    //Private recursive funtion for insert
    Node* insert(int x, Node* t);
    //Private recursive funtion for remove
    Node* remove(int x, Node* t);
    //Private recursive funtion for contain
    Node* contain(const int x, Node* t) const;
    //Private recursive funtion for maxNode
    Node* maxNode(Node* t) const;
};

/*
Standard implementation would have the deleted nodes actually
gone versus lazy deletion just sets a boolean value to true 
if its deleted buy it is not truly deleted.

Lazy Deletion causes issues because the nodes aren't
really deleted but insead marked as deleted. The issue occurs
when a specific number of nodes are marked deleted and they
slow down the search times to find nodes.
*/
#endif