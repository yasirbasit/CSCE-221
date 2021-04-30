#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

struct Node
{
  int value;
  Node* left;
  Node* right;
  int search_time; //see the problem description

  // Node constructor
  Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
    : value(val), left(l), right(r), search_time(0) {}
};

struct BSTree
{
public:
  BSTree():size(0),root(nullptr){};
  BSTree(const BSTree& other);
  // move constructor
  BSTree(BSTree&& other);
  // copy assignment
  BSTree& operator=(const BSTree& other);
  // move assignment
  BSTree& operator=(BSTree&& other);
  ~BSTree();

  const Node* get_root() const { return root; }
  const int get_size() const { return size; }
  Node* insert(int obj);
  Node* insert_helper(int obj, Node*&node, int st);
  Node* search(int obj);
  Node* search_helper(int obj, Node* node);
  void update_search_times();
  void update_st_helper(Node* node, int st);
  float get_average_search_time();
  void inorder(std::ostream& out);
  void inorder_helper(Node* node, std::ostream& out);
  void print_tree(std::ostream &out, Node* node);
  void print_node(std::ostream &out, Node* node);
  void print_level_by_level(std::ostream& out);
  // int getHeight() { return height; };
  int getHeight() {return (root == NULL) ? 0 : this->height(root);};
  int height(Node* t);

private:
  int size;
  Node* root;
  // int height=0;

  int get_total_search_time(Node* node);
  // you can add recursive helper functions to help you
  // this is one is implemented for you:
  void copy_helper(Node*& newNode, const Node* sourceNode);
  void deleteTree(Node* root);
};

// print a node
std::ostream& operator<<(std::ostream& out, Node node);

// print a BSTree
std::ostream& operator<<(std::ostream& out, BSTree& tree);

// read in a tree from a file
std::istream& operator>>(std::istream& in, BSTree& tree);


#endif
