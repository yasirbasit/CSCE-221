// Write a C++ recursive function that finds 
// the maximum value in an array (or vector) 
// of integers without using any loops.
#include<iostream>
int find_max(int A[], int n) {
	if(n == 1)
		return A[0];
	return std::max(A[n - 1], find_max(A, n - 1));
}

int main() {
	int A[] = {1,3,4,6,7,8,9,45,34,54};
	int n = sizeof(A) / sizeof(A[0]);
	for (int i = 0; i < 10; i++)
		std::cout << A[i] << " ";
	std::cout << "\nthe max value is: " << find_max(A, n) << std::endl;
	std::system("pause");
	return 0;
}