#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
struct Node {
	T data;
	Node<T>* next = nullptr;
	Node(T data) : data(data), next(nullptr){}
	Node() : data(0), next(nullptr){}
};

template <typename T>
class SortedMPQ: MPQ<T> {
private:
	Node<T>* Min;
	int size;
public:
	SortedMPQ();
	~SortedMPQ();
	T remove_min();
	T min(){if (is_empty()) throw std::runtime_error("Empty MPQ"); else return Min -> data;};
	bool is_empty(){return size == 0;};
	void insert(const T& data);
};

template <typename T>
SortedMPQ<T>::SortedMPQ():Min(nullptr),size(0){}

template <typename T>
SortedMPQ<T>::~SortedMPQ(){
	Node<T>* current = Min;
	while (current != nullptr) {
		Node<T>* deleteNode = current;
		current = current -> next;
		delete deleteNode;
	}
	Min = nullptr;
}

template <typename T>
T SortedMPQ<T>::remove_min(){
	if(is_empty()) throw std::runtime_error("Empty MPQ");
	T min_data = Min -> data;
	Node<T>* temp = Min;
	Min = Min -> next;
	delete temp;
	size--;
	return min_data;
}

template <typename T>
void SortedMPQ<T>::insert(const T& data){
	Node<T>* n = new Node<T>(data);
	if (Min == nullptr) {
		Min = n; size++;
	} else if (n -> data < Min -> data) {
		n -> next = Min; Min = n; size++;
	} else {
		Node<T>* curr = Min;
		Node<T>* prev = nullptr;
		while (curr && curr -> data < n -> data) {
			prev = curr; curr = curr -> next;
		}
		n -> next = curr; prev -> next = n;
		size++;
	}
}

#endif