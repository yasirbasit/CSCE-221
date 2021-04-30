#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
public:
    void insert(const T& data) {
        elements.push_back(data);
        up_heap(elements.size()-1);        
        size++;
    };
    bool is_empty() {return size == 0;};
    T min() {if(is_empty()) throw std::runtime_error("Empty MPQ"); else return elements.at(0);};
    T remove_min() {
        if(is_empty()) throw std::runtime_error("Empty MPQ");
        T temp = elements.at(0);
        elements.at(0) = elements.at(elements.size()-1);
        elements.pop_back();
        size--;
        down_heap(0);
        return temp;
    };
private:
    std::vector<T> elements{};
    int size = 0;
    void down_heap(int i);
    void up_heap(int i);

    //Pre-implemented helper functions
    void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
    int right_child(int i) {return 2*i + 2;}
    int left_child(int i) {return 2*i + 1;}
    int parent(int i) {return floor((i-1)/2);}
    bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
    bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i){
    int parent_index = parent(i);
    if(i > 0 && elements.at(i) < elements.at(parent_index)) {
        swap(i, parent_index);
        up_heap(parent_index);
    }
    // while(i > 0 && (elements.at(i) < elements.at(parent_index))) {
    //     swap(i, parent_index);
    //     i = parent_index;
    //     parent_index = parent(i);
    // }
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i){
    int right_index = right_child(i);
    int left_index = left_child(i);
    if (!is_internal(i)) return;
 
    if (is_leaf(i) || right_index >= size || (elements.at(i) < elements.at(right_index) && elements.at(i) < elements.at(left_index))) {
        if (right_index >= size && elements.at(left_index) < elements.at(i)) {
            swap(i,left_index);
            return;
        } 
        return;
    }
  
    int smaller;
    if (elements.at(left_index) < elements.at(right_index))
        smaller = left_index;
    else
        smaller = right_index;

    if (smaller) {
        swap(i, smaller);
        down_heap(smaller);
    }
}
#endif