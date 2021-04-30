// implementation of the DLList class

#include "DLList.h"

DLList::DLList() {
  header.next = &trailer;
  trailer.prev = &header;
}
DLList::DLList(const DLList& dll) {
  header.next = &trailer;
  trailer.prev = &header;
  // for (DLListNode* n = dll.header.next; n != &dll.trailer; n = n -> next)
  //  this -> insert_last(n -> obj);
  DLListNode* temp = dll.header.next;
  while (temp->next) {
    if(temp != &trailer){
     this -> insert_last(temp -> obj);
     temp = temp -> next;     
    }
  }
}
DLList::DLList(DLList&& dll) {
  // if (dll.is_empty()) {
  //   header.next = &trailer;
  //   trailer.prev = &header;
  // } else {
  //     header.next = dll.header.next;
  //     trailer.prev = dll.trailer.prev;
  //     dll.header.next = &dll.trailer;
  //     dll.trailer.prev = &dll.header;
  //     header.next -> prev = &header;
  //     trailer.prev -> next = &trailer;
  // }
  DLListNode *new_node = &header;
    DLListNode  *temp_node = dll.header.next;
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
}
DLList::~DLList() {
  // for (DLListNode* curr = header.next; curr != &trailer; curr = curr -> next)
  //  delete curr;
  DLListNode *nextNode = header.next;
  while (nextNode != &trailer) {
    nextNode = nextNode->next;
    delete header.next;
    header.next = nextNode;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
DLList& DLList::operator=(const DLList& dll) {
  if (this != &dll) {
    header.next = &trailer;
    trailer.prev = &header;
    // for (DLListNode* n = dll.header.next; n != &dll.trailer; n = n -> next)
    //  this -> insert_last(n -> obj);
    DLListNode* temp = dll.header.next;
    while (temp != dll.trailer.prev) {
      this -> insert_last(temp -> obj);
      temp = temp -> next;
    }
    this -> insert_last(temp -> obj);
  }
  return *this;
}
DLList& DLList::operator=(DLList&& dll) {
  //   if (this != &dll) {
  //     if (dll.is_empty()) {
  //       header.next = &trailer;
  //       trailer.prev = &header;
  //     } else {
  //       header.next = dll.header.next;
  //       trailer.prev = dll.trailer.prev;
  //       dll.header.next = &dll.trailer;
  //       dll.trailer.prev = &dll.header;
  //       header.next -> prev = &header;
  //       trailer.prev -> next = &trailer;
  //     }
  //   }
  // return *this;
  DLListNode *prev_node, *node = header.next;
    while(node != &trailer){
      prev_node = node;
      node = node -> next;
      delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
    DLListNode *prev_node_d,*temp_node = dll.header.next;
    while (temp_node != &dll.trailer)
    {
      this -> insert_last(temp_node -> obj);
      prev_node_d = temp_node;
      delete prev_node_d;
      temp_node = temp_node -> next;
    }
    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
    return *this;
}

DLListNode *DLList::first_node() const {
  return header.next;
}
const DLListNode *DLList::after_last_node() const {
  return &trailer;
}
bool DLList::is_empty() const {
  return header.next == &trailer;
}
int DLList::first() const {
  return header.next -> obj;
}
int DLList::last() const {
  return trailer.prev -> obj;
}
void DLList::insert_first(int obj) {
    DLListNode* n = new DLListNode(obj, &header, header.next);
    header.next -> prev = n;
    header.next = n;
}
int DLList::remove_first() {
  if (is_empty())
    throw("The LinkedList is empty...");
  DLListNode* temp = header.next;
  int data = temp -> obj;
  header.next = temp -> next;
  temp -> next -> prev = &header;
  delete temp;
  return data;
}
void DLList::insert_last(int obj){
  DLListNode* n = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev -> next = n;
  trailer.prev = n;
}
int DLList::remove_last() {
  if (is_empty())
    throw("The LinkedList is empty...");
  DLListNode* temp = trailer.prev;
  int data = temp -> obj;
  trailer.prev = temp -> prev;
  temp -> prev -> next = &trailer;
  delete temp;
  return data;
}
void DLList::insert_after(DLListNode &p, int obj) {
  DLListNode* next = p.next;
  DLListNode* n = new DLListNode(obj, &p, next);
  next -> prev = n;
  p.next = n;
}
void DLList::insert_before(DLListNode &p, int obj) {
  DLListNode* prev = p.prev;
  DLListNode* n = new DLListNode(obj, prev, &p);
  prev -> next = n;
  p.prev = n;
}
int DLList::remove_after(DLListNode &p) {
  if (p.next == &trailer || is_empty())
    throw("The LinkedList is empty...");
  DLListNode* temp = p.next;
  int data = temp -> obj;
  temp -> prev -> next = temp -> next;
  temp -> next -> prev = temp -> prev;
  delete temp;
  return data;  
}
int DLList::remove_before(DLListNode &p) {
  if (p.prev == &header || is_empty())
    throw("The LinkedList is empty...");
  DLListNode* temp = p.prev;
  int data = temp -> obj;
  temp -> prev -> next = temp -> next;
  temp -> next -> prev = temp -> prev;
  delete temp;
  return data;
}

ostream& operator<<(ostream& out, const DLList& dll){
  DLListNode *temp = dll.first_node();
  while(temp != dll.after_last_node()){
    out << temp -> obj << ", ";
    temp = temp -> next;
  }
  return out;
}