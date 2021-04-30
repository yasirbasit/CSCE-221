// Given two sorted lists, L1 and L2, 
// write an efficient C++ code to compute L1 ∩ L2 using only the basic STL list operations. 
#include <iostream>
#include <list>

using namespace std;

list<int> inter_list(list<int> L1, list<int> L2) {
	if(L1.empty() || L2.empty())
		std::exit(-1);
	L1.merge(L2);
	list<int> return_list;
	for(list<int>::iterator it = L1.begin() ; it != L1.end() ; it++) {
		if(*it == *--it) 
			return_list.push_back(*it);
		++it;
	}
	return return_list;
}

int main() { 
	int A1[]={1,2,3,4,5,6}; 
	int A2[]={2,4,6,8,9,10}; 
	list<int> iL1(A1, A1+6); 
	list<int> iL2(A2, A2+6); 
	list<int> iL3 = inter_list(iL1, iL2);
	list<int>::iterator it = iL3.begin(); 
	while(it != iL3.end()) { 
		cout << *it++ << " "; 
	}
	system("pause"); 
	return 0; 
}