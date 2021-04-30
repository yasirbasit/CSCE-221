#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

using namespace std;

/*
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
private:
	std::vector<T> v;
public:
	T remove_min(){
		if(is_empty()) throw std::runtime_error("Empty MPQ");
		int min_index = 0,sz=v.size();T min_value=v[0];
		for (int i = 1; i < sz; ++i)
			if (v.at(i) < min_value) min_index = i,min_value=v.at(i);
		v.at(min_index) = v.at(v.size()-1);
		v.pop_back();
		return min_value;
	};
	T min(){
		if(is_empty()) throw"Empty MPQ"; 
		T min = v.at(0);
		for (int i = 1; i < v.size(); ++i)
			if (v.at(i) < min) min = v.at(i);
		return min;
	};
	bool is_empty(){return v.size() == 0;};
	void insert(const T& data) {v.push_back(data);};


};

#endif