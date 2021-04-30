// Write a C++ function that counts the total number of nodes 
// with two children in a binary tree 
// (do not count nodes with one or none child). 
// You can use a STL container if you need to use an additional data structure 
// to solve this problem. Use the big-O notation to classify your algorithm. 
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> nodes;

struct BiTNode {
	int data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
};

void create_tree(BiTNode* &tree) {
    int data;
    cin >> data;
    if (data != '\n') {
        if (data == -1) {
            tree = nullptr;
        } else {
            tree = new BiTNode;
            tree->data = data;
            create_tree(tree->lchild);
            create_tree(tree->rchild);
        }
    }
}

void pre_order_traverse(BiTNode* &tree) {
    if (tree) {
        cout << tree->data << " ";
        pre_order_traverse(tree->lchild);
        pre_order_traverse(tree->rchild);
    }
}

void count_node(BiTNode* &tree) {
	cout << "data: " << tree -> data;
	if(tree -> lchild != nullptr && tree -> rchild != nullptr)
		nodes.push_back(tree -> data);
	if(tree -> lchild == nullptr && tree -> rchild == nullptr)
		return;
	count_node(tree->lchild);
	count_node(tree->rchild);
}

int main() {

    BiTNode* T;
    create_tree(T); 
    /*
    input here is:
    2 3 5 -1 -1 6 -1 -1 4 -1 -1
         2
	    /  \
	   3    4
	  / \
	 5	 6
    */
    pre_order_traverse(T); //2, 3, 5, 6, 4
    count_node(T);
    cout << "\nthe nodes are: " <<endl;
    for (int j = 0; j < nodes.size(); j++) 
    	cout << nodes[j] << " ";
    cout << "\nthe number of node with two children is: " << nodes.size() << endl;
	system("pause");
	return 0;
}

