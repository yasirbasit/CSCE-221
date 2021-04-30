#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include <stdexcept>
#include <list>
#include <random>
#include <iostream>
#include <algorithm>
#include "MPQ.h"
#include "BinaryHeap.h"

using namespace std;

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
public:
	BinaryHeap<T> mpq;
	void insert(const T& data) {mpq.insert(data);};
    bool is_empty() {return mpq.is_empty();};
    T min() {return mpq.min();};
    T remove_min() {return mpq.remove_min();};
};

#endif

using namespace std;
int main() {
	BinaryHeapMPQ<int> h;
	// int input[10] = {6,5,3,8,7,9,1,4,2,10};
	int input[10] = {10,9,8,7,6,5,4,3,2,1};


	for(int i = 0; i < 10; i++){
	  cout << "insert " << input[i] << endl;	  
	  h.insert(input[i]);
	  cout << "finished insert" << endl << endl;
	}
	std::sort(input,input+10);
	cout << "Expected Output:" << endl;
	for(int i = 0; i < 10; i++){
	  cout << input[i] << ' ';
	}
	cout << endl;
	cout << "Your Output:" << endl;
	for(int i = 0; i < 10; i++){
	  if(h.min() != input[i]){
	    cout << h.min() << " out of order removal" << endl;
	  }
	  int n = h.remove_min();

	  cout << n << ' ';
	}
	cout << "finished" << endl;
}