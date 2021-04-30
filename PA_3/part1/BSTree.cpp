#include "BSTree.h"

#include <iostream>
#include <exception>
#include <vector>
#include <queue>

using namespace std;

// Exception for empty BSTree
struct EmptyBSTree:public exception{virtual const char* what() const throw() {return "BSTree is empty.";}};

///////////////////////////////////
// Already Implemented Functions //
///////////////////////////////////

// These functions are already implemented for you. Scroll below to
// see the functions that you have to implement 

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
    tree.print_level_by_level(out);
    return out;
}

ostream& operator<<(ostream& out, Node& node)
{
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator>>(istream& in, BSTree& tree)
{
    /*
      take input from the in stream, and build your tree
      input will look like
      4 
      2 
      6 
      1 
      3 
      5 
      7
    */
    int next;
    while(in >> next) {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
void BSTree::copy_helper(Node*& newNode, const Node* sourceNode) {
    //Don't copy if the node is nullptr
    if(sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr)
        copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if(sourceNode->right != nullptr)
        copy_helper(newNode->right, sourceNode->right);
}

// recursive function
int BSTree::get_total_search_time(Node* node)
{
  if (node != nullptr) {
    return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
  }
  return 0;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
  
  return ((float)total_search_time)/size;
}


///////////////////////////////////
//     Functions to Implement    //
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or create new helper functions

// copy constructor
BSTree::BSTree(const BSTree& other):root(nullptr) {
  // if(other.get_root() != nullptr){
  //   root=new Node(other.get_root()->value);
  //   root->search_time=1;
  // }
  if (this != &other) {
    size=other.size;  
    copy_helper(root,other.root);
  }
}

// move constructor
BSTree::BSTree(BSTree&& other){
  root=other.root;
  size=other.size;
  // copy_helper(root,other.get_root());
  other.root=nullptr;
  other.size=0;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other) {
  if(this!=&other){
    this -> ~BSTree();
    if(other.root==nullptr)
      return *this;
    // else{
    //   root = new Node(other.get_root()->value);
    //   root->search_time=1;
    // }
    this->size=other.size;    
    copy_helper(this -> root,other.root);
  }
  return *this;
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other) {
  if(this!=&other){
    deleteTree(root);
    // root = new Node();
    // root->search_time=1;
    // copy_helper(root,other.get_root());
    root=other.root;
    size=other.get_size();
    other.root=nullptr;
    other.size=0;
  }
  return *this;
}

// destructor
BSTree::~BSTree() {
    // Make sure to call delete on every node of the tree
    // You can use a recursive helper function to do this
    deleteTree(root);
    root=nullptr;
    size=0;
}

void BSTree::deleteTree(Node* root) {
  if (root == nullptr) return;
  if (root-> left !=nullptr) deleteTree(root -> left);
  if (root-> right !=nullptr) deleteTree(root -> right);
  delete root;
}

Node* BSTree::insert(int obj) {
    /* insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node */
  size++;
  return insert_helper(obj,root,1);
}

Node* BSTree::insert_helper(int obj, Node*&node, int st) {
  if(node==nullptr) {
    node=new Node(obj);
    node->search_time=st;
    return node;
  } else if(obj < node->value)
    return insert_helper(obj,node->left,st+1);
  else
    return insert_helper(obj,node->right,st+1);
}

Node* BSTree::search(int obj) {
    /* recursively search down the tree to find the node that contains obj
    if you don't find anything return nullptr */
  return search_helper(obj,root);
}

Node* BSTree::search_helper(int obj, Node* node){
  if(node == nullptr || node->value == obj)
      return node;
    if(node->value < obj)
      return search_helper(obj,node->right);
    return search_helper(obj,node->left);
}

void BSTree::update_search_times() {

    /* do a BFS or DFS of your tree and update the search times of all nodes at once
      The root has a search time of 1, and each child is 1 more than its parent */
  return update_st_helper(root,1);
}

void BSTree::update_st_helper(Node* node, int st){
  if(node==nullptr)
    return;
  node->search_time=st;
  update_st_helper(node->left,st+1);
  update_st_helper(node->right,st+1);
}

void BSTree::inorder(ostream& out) {
    /* print your nodes in infix order
    If our tree looks like this:

       4
     2   6
    1 3 5 7

    It should output:
    1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]
    You can use the << operator to print the nodes in the format shown */
  inorder_helper(this->root,out);
}

void BSTree::inorder_helper(Node* node, ostream& out) {
  if(node==nullptr)
    return;
  inorder_helper(node->left,out);
  out<<node->value<<"["<<node->search_time<<"] ";
  inorder_helper(node->right,out);
}

void BSTree::print_tree(ostream &out, Node* node){
  out<<endl;
  print_tree(out,node);
  out<<endl;
}

void BSTree::print_level_by_level(ostream& out) {

    /* Print the tree using a BFS so that each level contains the values for a level of the tree.
    Use X to mark empty positions. 
    
      if our tree looks like this:

       4
     2   6
    1   5 7
           9

    it should output:

    4[1]
    2[2] 6[2]
    1[3] X 5[3] 7[3]
    X X X X X X X 9[4]

    it might be helpful to do this part with the std::queue data structure.
    Hint: the Nth level contains 2^(N-1) nodes (with a value or with an X). Watch out
    for nodes like the left child of 6 above, and print the descendents of an empty
    node as also empty
    You can use the << operator to print nodes in the format shown */

    // Base Case  
    // if (root == NULL) return;
    // queue<Node*> q1;
    // queue<Node*> q2;
    // Node* p = root;
    // q1.push(p);
    // int level = p->search_time; 
    // Node* current = p;
    // if (getHeight()==0) {
    //   out << root->value << "[" << root->search_time << "]" << " ";
    //   return;
    // }
    // while (level < getHeight()+1) {
    //   while (q1.size() > 0) {
    //     current = q1.front();
    //     if (current->left == NULL)
    //       q2.push(NULL);
    //     else
    //       q2.push(current->left);
    //     if (current->right == NULL)
    //       q2.push(NULL);
    //     else
    //       q2.push(current->right);
    //     if (current->value < 0){
    //       out << "X ";
    //     }
    //     else {
    //       out << current->value << "[" << current->search_time << "]" << " ";
    //     }
    //     level = q1.front()->search_time;
    //     q1.pop();
    //   }
    //   out << endl;
    //   while (q2.size() > 0) {
    //     if (q2.front() != NULL) {
    //       q1.push(q2.front());
    //       q2.pop();
    //     }
    //     else {
    //       // INSERTS DUMMY INTEGER VALUE
    //       Node* n = new Node(-1);
    //       q1.push(n);
    //       q2.pop();
    //     }
    //   }
    // }

  queue<Node*> tree;
  tree.push(root);
  int eleInLevel = 1; // elements in the temp level
  bool notNull = false;
  //out << endl;
  while(eleInLevel > 0){
    Node* temp = tree.front();
    tree.pop();
    eleInLevel--;
    if(temp != nullptr){
      //out << "\n" << temp->value << "[" << temp->search_time << "]";
      out << temp->value << "[" << temp->search_time << "]" << " ";
      if(temp->left != nullptr) { tree.push(temp->left); }
      else{tree.push(nullptr);}
      if(temp->right != nullptr) { tree.push(temp->right); }
      else{tree.push(nullptr);}
      if(temp->left != nullptr || temp->right != nullptr){ notNull = true; }
    } else {
      out << "X ";  
      tree.push(nullptr);
      tree.push(nullptr);
    }
    if(eleInLevel == 0){ // reach the end of the current level
      out << endl;
      if(notNull == true){ // the next level is non-empty
        notNull = false;
        eleInLevel = tree.size();
      }
    }
  }
}

int BSTree::height(Node* t){
  if(t == NULL)
    return -1;
  else {
    int LeftHeight = height(t->left);
    int RightHeight = height(t->right);
    return (LeftHeight > RightHeight) ? 1+LeftHeight : 1+RightHeight;
  }
}
