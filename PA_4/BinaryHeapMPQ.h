#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
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