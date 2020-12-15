#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

class Binary_Search {
private:
	int num_comp = 0;
	int num_find;

public:
	std::vector<int> vec;
	// constructor
	Binary_Search(const std::vector<int> &v, int x) : num_find(x) {
		for (int i = 0; i < v.size(); i++)
			vec.push_back(v[i]);
	}

	int Bi_Search() {
		int mid; 
		int low = 0;     
		int high = (int) vec.size()-1;     
	   	while (low < high) {
	      	mid = (low + high) / 2;  
	      	cout << "mid: " << mid << endl;                
	      	if (num_comp++, vec[mid] < get_num_find()) high = mid - 1;
	      	else if (vec[mid] == get_num_find()) high = mid;     
	      	else low = mid + 1;     
	   	}     
	   	if (num_comp++, num_find == vec[high]) return high; //OK: found          
	   	throw "sth wrong..."; // Unsuccessful_Search(); //exception: not found 
	}

	int get_num_find() const {
		return num_find;
	}

	int get_num_comp() const {
		return num_comp;
	}

	void print_out() {
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << endl;
		cout << "finished printing" << endl;
	}

};


int main() {
	vector<int> v;
	int k;
	cin >> k;
	int n = pow(2, k);
	cout << "The number of vector: " << n << endl;
	for (int i = n; i >= 1; i--) {
		v.push_back(i);
	}

	Binary_Search bs(v, n);
	cout << "finished constructor" << endl;
	bs.print_out();
	bs.Bi_Search();
	cout << "finished function" << endl;
	cout << bs.get_num_comp() << endl;

	return 0;
}