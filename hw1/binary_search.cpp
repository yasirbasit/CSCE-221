#include <iostream>
#include <vector>
#include<math.h>

using namespace std;
int num_comp = 0;

// int Binary_Search(vector<int> &v, int x) {
//    int mid, low = 0;     
//    int high = (int) v.size()-1;     
//    while (low < high) {         
//       mid = (low+high)/2;                 
//       if (num_comp++, v[mid] < x) low = mid+1;         
//       else high = mid;     
//    }     
//    if (num_comp++, x == v[low]) return low; //OK: found          
//    throw "sth wrong..."; // Unsuccessful_Search(); //exception: not found 
// } 


int SearchAlgorithm(std::vector<int> &v, int x) {                                                                                
     
  int m, i = 0;
  int j = v.size()-1;
  while (i < j) {
     m = (i+j)/2;
     if (num_comp++, v[m] < x) i = m+1;
     else j = m;
  }
  if (num_comp++, x == v[i]) return i; //found
  throw ("UnsuccessfulSearch()"); //not found
}



int main() {
	vector<int> v;
	int k = 10;
	// cin >> k;
	int n = pow(4, k);
	// cout << "The number of vector: " << n;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}
	// cout << "Last element: " << v.at(n - 1) << endl;
	// cout << "position: " << Binary_Search(v, n - 1);
	// cout << "\n" << "num_comp: " << num_comp;
	cout << SearchAlgorithm(v, n - 1) << endl;
	cout << num_comp << endl;
	return 0;
}