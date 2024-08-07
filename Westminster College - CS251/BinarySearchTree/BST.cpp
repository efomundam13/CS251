#include "BST.h"

/*
Node class
Creates root node
*/
struct LazyBST::Node
{
    Node(int x, Node* l, Node* r) : val(x), left(l), right(r){}
    Node() : Node(0, nullptr, nullptr){}

    int val;
	Node* left, * right;
};

LazyBST::LazyBST() : root(nullptr) {}

LazyBST::~LazyBST() {}

void LazyBST::insert(int x) {
   root = insert(x, root);
}

void LazyBST::remove(int x) {
    root = remove(x, root);
}

bool LazyBST::contain(int x) const
{
    Node* node = contain(x, root);
	return (node != nullptr);
};

LazyBST::Node* LazyBST::insert(int x, Node* t)
{
    if(t == nullptr)
    {
        Node* newNode = new Node(x, nullptr, nullptr);
        return newNode;
    }


    if(t->val == x)
        return t;
    
    if(x < t->val)
        t->left = insert(x, t->left);
    else
        t->right = insert(x, t->right);

    return t;
}

LazyBST::Node* LazyBST::contain(int x, Node* t) const
{
    if(t == nullptr)
		return nullptr;
	if (x == t->val)
		return t;
	else if (x < t->val) {
		if (t->left == nullptr)
			return nullptr;
		else
			return contain(x, t->left);
	}
	else if (x > t->val) {
		if (t->right == nullptr)
			return nullptr;
		else
			return contain(x, t->right);
	}
	return nullptr;
}

LazyBST::Node* LazyBST::remove(int x, Node* t)
{
    if (t == nullptr)
		return nullptr;

	if (x < t->val) {
		t->left = remove(x, t->left);
	}
	else if (x > t->val) {
		t->right = remove(x, t->right);
	}
	else { 
		//no children
		if (t->left == nullptr && t->right == nullptr) {
			delete t;
			t = nullptr;
		}
		//1 child
		else if (t->left == nullptr) {
			Node* tmp = t->right;
			delete t;
			t = tmp;
		}
		else if (t->right == nullptr) {
			Node* tmp = t->left;
			delete t;
			t = tmp;
		}
		//2 children
		else {
			Node* swapnode = maxNode(t->left);
			t->val = swapnode->val;
			t->left = remove(swapnode->val, t->left);
		}
	}
	return t;
}

LazyBST::Node* LazyBST::maxNode(Node* t) const {

	if (t == nullptr)
		return nullptr;
	if (t->right == nullptr)
		return t;
	return maxNode(t->right);
}


int main()
{
    LazyBST myTree;

    myTree.insert(1);
    myTree.insert(7);
    myTree.insert(13);
    myTree.insert(6);
    myTree.insert(4);
    myTree.insert(20);

    if(myTree.contain(6) == true)
        cout << "Value was found" << endl;
    else
        cout << "Value was not found" << endl;

    if(myTree.contain(9) == true)
        cout << "Value was found" << endl;
    else
        cout << "Value was not found" << endl;

    myTree.remove(6);
    if(myTree.contain(6) == false)
        cout << "Remove was successful" << endl;
    else
        cout << "Remove was not successful" << endl;

    myTree.insert(9);
    if(myTree.contain(9) == true)
        cout << "Value was found" << endl;
    else
        cout << "Value was not found" << endl;

	return 0;
}
