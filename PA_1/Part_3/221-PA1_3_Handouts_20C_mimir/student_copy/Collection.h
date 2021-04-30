/*
 * @Author: Rong Xu
 * @Date: 2020-09-10 02:05:16
 * @LastEditTime: 2020-09-22 08:32:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /PA_1/Part_3/221-PA1_3_Handouts_20C_mimir/student_copy/Collection.h
 */
#ifndef Collection_H
#define Collection_H
#include <string>
#include <iostream>
using namespace std;

enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

template<class Obj, class F1, class F2>
class Collection {
private:
    Obj * array;
    int size;
    int capacity;
    void resize() {
        if (capacity == 0)
            capacity = 1;
        else
            capacity *= 2;
        Obj* A = new Obj[capacity];
        for (int i = 0; i < size; i++) {
            A[i] = array[i];
        }
        if (array != nullptr)
            delete[] array;
        array = A; 
    }

public:
    Collection() : size(0), capacity(0), array(nullptr){};
    Collection(int cap) : size(0), capacity(cap), array(new Obj[cap]){};
    Collection(const Collection& c) : size(c.size), capacity(c.capacity), array(new Obj[c.capacity]) {
		for (int i = 0; i < size; i++) {
			array[i] = c.array[i];
		}
    };
    Collection& operator=(const Collection& c) {
		if (this != &c) {
			// delete[] array;
			size = c.size;
			capacity = c.capacity;
			Obj* newarray = new Obj[size];
			for (int i = 0; i < size; i++) {
				array[i] = c.array[i];
			}
			delete[] c.array;
			array = newarray;
		}
		return *this;
	};
    ~Collection() {make_empty();};
    Collection(Collection&& c) : size(c.size), capacity(c.capacity), array(c.array) {
		c.size = 0;
		c.capacity = 0;
		c.array = nullptr;
	};
    Collection& operator=(Collection&& c) {
		if (this != &c) {
			delete[] array;
			size = c.size;
			capacity = c.capacity;
			array = c.array;
			c.size = 0;
			c.capacity = 0;
			c.array = nullptr;
		}
		return *this;
	};
    void insert_item(const Obj& ob) {
		if(size == capacity) {
			resize();
		}
		array[size] = ob;
		size++;
	};
    bool contains(const Obj& ob) const {
		for (int i = 0; i < size; i++) {
			if (array[i] == ob)
				return true;
		}
		return false;
	};
    Obj remove_any_item() {
		if(is_empty())
			throw "Exception: the collection is already empty";
		srand (time(0));
		int dele_index = rand() % size;
		Obj A = array[dele_index];

	    for(int i = 0; i < size; i++){
	        if(array[i] == A){
	            for(int j = 0; i + j < size; j++)
	                array[i+j] = array [i + j + 1];
	            size--;
	            break;
	        }
	    }
	    return A;
	};
    void remove_this_item(const Obj& ob) {
		if(is_empty())
			throw "Exception: the collection is already empty";
		
	    for(int i = 0; i < size; i++){
	        if(array[i] == ob){
	            for(int j = 0; i + j < size; j++)
	                array[i+j] = array [i + j + 1];
	            size--;
	            break;
	        }
	    }
	};
    void make_empty() {
		delete[] array;
		array = nullptr;
		size = 0;
		capacity = 0;
	};
    bool is_empty() const {return (size == 0);};
    int total_items() const {return size;};
    int total_items(F2 s) const {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (array[i].get_size() == s)
				count++;
		}	
		return count;
	};
    int total_items(F1 c) const {
		int count = 0;
		for (int i = 0; i < this -> size; i++) {
			if (array[i].get_color() == c)
				count++;
		}
		return count;
	};
    void print_items() const {
		for (int i = 0; i < size; i++)
			cout << array[i] << endl;
	};
    Obj& operator[](int i) {return array[i];};
    const Obj& operator[](int i) const {return array[i];};
};

template<class Obj, class F1, class F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2) {
	Collection<Obj, F1, F2> temp;
	for (int i = 0; i < c1.total_items(); i++)
		temp.insert_item(c1[i]);
	for (int j = 0; j < c2.total_items(); j++)
		temp.insert_item(c2[j]);
	return temp;
}

template<class Obj, class F1, class F2>
void swap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2) {
	Collection<Obj, F1, F2> temp1 = move(c1);
	c1 = move(c2);
	c2 = move(temp1);
}

template<class Obj, class F1, class F2>
void sort_by_size(Collection<Obj, F1, F2>& c, Sort_choice sort) {
	switch (sort) {
		case Sort_choice::bubble_sort:
			for (int i = 0; i < c.total_items(); i++) {
				for (int j = 0; j < c.total_items() - 1; j++) {
					if (c[i].get_size() < c[j].get_size())
						std::swap(c[i], c[j]);
				}
			}
			break;
		case Sort_choice::insertion_sort:
			int preIndex;
			for (int i = 1; i < c.total_items(); i++) {
				preIndex = i - 1;
				Obj temp = c[i];
				while (preIndex >= 0 && c[preIndex].get_size() > temp.get_size()) {
					c[preIndex + 1] = c[preIndex];
					preIndex--;
				}
				c[preIndex + 1] = temp;
			}
			break;
		case Sort_choice::selection_sort:
			int minIndex; 
			Obj temp;
			for(int i = 0; i < c.total_items() - 1; i++) {
				minIndex = i;
				for (int j = i + 1; j < c.total_items(); j++) {
					if (c[j].get_size() < c[minIndex].get_size())
						minIndex = j;
				}
				temp = c[i];
				c[i] = c[minIndex];
				c[minIndex] = temp;
			}
			break;
	}
}
#endif