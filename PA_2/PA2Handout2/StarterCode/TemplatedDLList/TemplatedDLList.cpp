#include "TemplatedDLList.h"

template <typename T>

DLList::DLList() {
	header.next = &trailer;
	trailer.prev = &header;
}

DLList::DLList(const DLList<T>& dll) {
	header.next = &trailer;
	trailer.prev = &header;
	for (DLListNode* n = dll.first_node(); n != dll.after_last_node(); n = n -> next)
		this -> insert_last(n -> obj);
}

DLList::DLList(DLList<T>&& dll) {
	if (dll.is_empty()) {
		header.next = &trailer;
		trailer.prev = &header;
	} else {
		header.next = dll.first_node();
		trailer.prev = dll.trailer.prev;
		dll.header.next = &dll.trailer;
		dll.trailer.prev = &dll.header;
		header.next -> prev = &header;
		trailer.prev -> next = &trailer;
	}
}

DLList::~DLList() {
	clear();
}

DLList<T>& DLList::operator=(const DLList<T>& dll) {
	if (this != &dll) {
		clear();
		for (DLListNode* n = dll.first_node(); n != dll.after_last_node(); n = n -> next)
			this -> insert_last(n -> obj);
	}
	return *this;
}
DLList<T>& DLList::operator=(DLList<T>&& dll) {
    if (this != &dll) {
	if (dll.is_empty()) {
		header.next = &trailer;
		trailer.prev = &header;
	} else {
		header.next = dll.first_node();
		trailer.prev = dll.trailer.prev;
		dll.header.next = &dll.trailer;
		dll.trailer.prev = &dll.header;
		header.next -> prev = &header;
		trailer.prev -> next = &trailer;
	}

}

void DLList::clear() {
    DLListNode<T> *nextNode = header.next;
    while (nextNode != &trailer) {
		nextNode = nextNode->next;
		delete header.next;
		header.next = nextNode;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

T DLList::first() const {
	return header.next;
}

T DLList::last() const {
	return &trailer;
}

void DLList::insert_first(T obj) {
	DLListNode* n = new DLListNode(obj);
	DLListNode* temp = header.next;
	header.next = n;
	n -> prev = &header;
	n -> next = temp;
}
T DLList::remove_first() {
	if (is_empty())
		throw("The LinkedList is empty...");
	DLListNode* temp = header.next;
	T data = temp -> obj;
	header.next = temp -> next;
	temp -> next -> prev = &header;
	delete temp;
	return data;
}

void DLList::insert_last(T obj){
	DLListNode* n = new DLListNode(obj, trailer.prev, &trailer);
	trailer.prev -> next = n;
	trailer.prev = n;
}

T DLList::remove_last() {
	if (is_empty())
		throw("The LinkedList is empty...");
	DLListNode* temp = trailer.prev;
	T data = temp -> obj;
	trailer.prev = temp -> prev;
	temp -> prev -> next = &trailer;
	delete temp;
	return data;
}

void DLList::insert_after(DLListNode<T> &p, T obj) {
    DLListNode<T>* n = new DLListNode<T>(obj, &p, p.next);
    p.next -> prev = n;
    p.next = n;
}

void DLList::insert_before(DLListNode<T> &p, T obj) {
    DLListNode<T>* n = new DLListNode<T>(obj, p.prev, &p);
    p.prev -> next = n;
    p.prev = n;
}

T DLList::remove_after(DLListNode<T> &p) {
    if (p.next == &trailer || is_empty())
    	throw("The LinkedList is empty...");
    DLListNode<T>* temp = p.next;
    T data = temp -> obj;
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    delete temp;
    return data; 	
}

T DLList::remove_before(DLListNode<T> &p) {
	if (is_empty())
		throw("The LinkedList is empty...");
	DLListNode<T>* temp = p.prev;
	T data = temp -> obj;
	p.prev = temp -> prev;
	temp -> prev -> next = &p;
	delete temp;
	return data;
}

ostream& operator<<(ostream& out, const DLList& dll){
	DLListNode<T> *temp = dll.first_node();
	while(temp != dll.after_last_node()){
		out << temp -> obj << ", ";
		temp = temp -> next;
	}
	return out;
}