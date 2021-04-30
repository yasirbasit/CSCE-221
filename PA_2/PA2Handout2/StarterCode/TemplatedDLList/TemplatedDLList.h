// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
#include <stdexcept>
#define EmptyLinkedListException

using namespace std;

template <typename T>
class DLList; // class declaration

// doubly linked list node
template <typename T>
struct DLListNode {
  T obj;
  DLListNode<T> *prev, *next;
  // constructor
  DLListNode(T e=T(), DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n) {}
};

// doubly linked list class
template <typename T>
class DLList {
private:
  DLListNode<T> header, trailer;
public:
  DLList() : header(T()), trailer(T()) {
    header.next = &trailer;
    trailer.prev = &header;
  };// default constructor
  DLList(const DLList<T>& dll) {
    header.next = &trailer;
    trailer.prev = &header;
    DLListNode<T>* temp = dll.header.next;
    while (temp->next) {
      if(temp != &trailer){
       this -> insert_last(temp -> obj);
       temp = temp -> next;     
      }
    }
  }; // copy constructor
  DLList(DLList&& dll) :header(0),trailer(0) {
    // if (dll.is_empty()) {
    //   header.next = &trailer;
    //   trailer.prev = &header;
    // } else {
    //   header.next = dll.first_node();
    //   trailer.prev = dll.trailer.prev;
    //   dll.header.next = &dll.trailer;
    //   dll.trailer.prev = &dll.header;
    //   header.next -> prev = &header;
    //   trailer.prev -> next = &trailer;
    // }
    DLListNode<T> *new_node = &header;
    DLListNode<T>  *temp_node = dll.header.next;
    while(temp_node != &dll.trailer){
      if(new_node == &header)
        header.next = temp_node;
      else
        new_node -> next = temp_node;
      temp_node -> prev = new_node;
      new_node = new_node -> next;
      new_node -> obj = temp_node -> obj;
      temp_node = temp_node -> next;
    }
    new_node -> next = &trailer;
    trailer.prev = new_node;
    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
  }; // move constructor
  ~DLList() {clear();}; // destructor
  DLList<T>& operator=(const DLList<T>& dll) {
    if (this != &dll) {
      header.next = &trailer;
      trailer.prev = &header;
      // for (DLListNode* n = dll.header.next; n != &dll.trailer; n = n -> next)
      //  this -> insert_last(n -> obj);
      DLListNode<T>* temp = dll.header.next;
      while (temp != dll.trailer.prev) {
        this -> insert_last(temp -> obj);
        temp = temp -> next;
      }
      this -> insert_last(temp -> obj);
    }
    return *this;
  }; // copy assignment operator
  DLList<T>& operator=(DLList<T>&& dll) {
    // if (this != &dll) {
    //   if (dll.is_empty()) {
    //     header.next = &trailer;
    //     trailer.prev = &header;
    //   } else {
    //     clear();
    //     header.next = dll.first_node();
    //     trailer.prev = dll.trailer.prev;
    //     dll.header.next = &dll.trailer;
    //     dll.trailer.prev = &dll.header;
    //     header.next -> prev = &header;
    //     trailer.prev -> next = &trailer;
    //   }
    // }
    // return *this;
    DLListNode<T> *prev_node, *node = header.next;
    while(node != &trailer){
      prev_node = node;
      node = node -> next;
      delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
    DLListNode<T> *prev_node_d,*temp_node = dll.header.next;
    while (temp_node != &dll.trailer)
    {
      this->insert_last(temp_node->obj);
      prev_node_d = temp_node;
      delete prev_node_d;
      temp_node = temp_node -> next;
    }
    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
    return *this;
  }; // move assignment operator
  void clear() {
    // for (DLListNode<T>* curr = header.next; curr != &trailer; curr = curr -> next)
    //   delete curr;
    DLListNode<T> *nextNode = header.next;
    while (nextNode != &trailer) {
      nextNode = nextNode->next;
      delete header.next;
      header.next = nextNode;
    }
    header.next = &trailer;
    trailer.prev = &header;
  }
  // return the pointer to the first node
  DLListNode<T> *first_node() const { return header.next; } 
  // return the pointer to the trailer
  const DLListNode<T> *after_last_node() const { return &trailer; }
  // return if the list is empty
  bool is_empty() const { return header.next == &trailer; }
  T first() const {return header.next -> obj;}; // return the first object
  T last() const {return trailer.prev -> obj;}; // return the last object
  void insert_first(T obj) {
    DLListNode<T>* n = new DLListNode<T>(obj, &header, header.next);
    header.next -> prev = n;
    header.next = n;
  }; // insert to the first node
  T remove_first() {
    if (is_empty())
      throw("The LinkedList is empty...");
    DLListNode<T>* temp = header.next;
    T data = temp -> obj;
    header.next = temp -> next;
    temp -> next -> prev = &header;
    delete temp;
    temp = nullptr;
    return data;
  }; // remove the first node
  void insert_last(T obj) {
    DLListNode<T>* n = new DLListNode<T>(obj, trailer.prev, &trailer);
    trailer.prev -> next = n;
    trailer.prev = n;
  }; // insert to the last node
  T remove_last() {
    if (is_empty())
      throw("The LinkedList is empty...");
    DLListNode<T>* temp = trailer.prev;
    T data = temp -> obj;
    trailer.prev = temp -> prev;
    temp -> prev -> next = &trailer;
    delete temp;
    temp = nullptr;
    return data;
  }; // remove the last node
  void insert_after(DLListNode<T> &p, T obj) {
    DLListNode<T>* n = new DLListNode<T>(obj, &p, p.next);
    p.next = n;    
    n -> next -> prev = n;
  };
  void insert_before(DLListNode<T> &p, T obj) {
    DLListNode<T>* n = new DLListNode<T>(obj, p.prev, &p);
    n -> prev -> next = n;
    p.prev = n;
  };
  T remove_after(DLListNode<T> &p) {
    if (p.next == &trailer || is_empty())
      throw("The LinkedList is empty...");
    DLListNode<T>* temp = p.next;
    T data = temp -> obj;
    p.next = temp -> next;
    temp -> next -> prev = &p;
    delete temp;
    return data;  
  };

  T remove_before(DLListNode<T> &p) {
    if (p.prev == &header || is_empty())
      throw("The LinkedList is empty...");
    DLListNode<T>* temp = p.prev;
    T data = temp -> obj;
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    delete temp;
    temp = nullptr;
    return data;
  };
};

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll){
  DLListNode<T> *temp = dll.first_node();
  while(temp != dll.after_last_node()){
    out << temp -> obj << ", ";
    temp = temp -> next;
  }
  return out;
};


#endif