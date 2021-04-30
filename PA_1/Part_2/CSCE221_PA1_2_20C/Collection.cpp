/*
Name: Rong Xu
UIN: 928009312
Section: CSCE221-511
Project: PA1_part2
*/
#include "Collection.h"
#include "Stress_ball.h"
#include <ctime>

using namespace std;
void Collection::resize() {
	if (capacity == 0)
		capacity = 1;
	else
		capacity *= 2;
    Stress_ball* A = new Stress_ball[capacity];
    for (int i = 0; i < size; i++) {
        A[i] = array[i];
    }
    if (array != nullptr)
    	delete[] array;
    array = A;
}

Collection::Collection() : size(0), capacity(0), array(nullptr){}

Collection::Collection(int cap) : size(0), capacity(cap), array(new Stress_ball[cap]){}

Collection::Collection(const Collection& c) : size(c.size), capacity(c.capacity), array(new Stress_ball[c.capacity]) {}

Collection& Collection::operator=(const Collection& c) {
	if (this != &c) {
		// delete[] array;
		size = c.size;
		capacity = c.capacity;
		Stress_ball* newarray = new Stress_ball[size];
		for (int i = 0; i < size; i++) {
			array[i] = c.array[i];
		}
		delete[] c.array;
		array = newarray;
	}
	return *this;
}

Collection::~Collection() {
	make_empty();
}

Collection::Collection(Collection&& c) : size(c.size), capacity(c.capacity), array(c.array) {
	c.size = 0;
	c.capacity = 0;
	c.array = nullptr;
}

Collection& Collection::operator=(Collection&& c) {
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
}

void Collection::insert_item(const Stress_ball& sb) {
	if(size == capacity) {
		resize();
	}
	array[size] = sb;
	size++;
}

bool Collection::contains(const Stress_ball& sb) const {
	for (int i = 0; i < size; i++) {
		if (array[i] == sb)
			return true;
	}
	return false;
}

Stress_ball Collection::remove_any_item() {
	if(is_empty())
		throw "Exception: the collection is already empty";
	srand (time(0));
	int dele_index = rand() % size;
	Stress_ball A = array[dele_index];

    for(int i = 0; i < size; i++){
        if(array[i] == A){
            for(int j = 0; i + j < size; j++)
                array[i+j] = array [i + j + 1];
            size--;
            break;
        }
    }

	// for (int i = dele_index; i < size; i++)
	// 	array[i] = array[i + 1];
	// size--;
	return A;
}

void Collection::remove_this_item(const Stress_ball& sb) {
	if(is_empty())
		throw "Exception: the collection is already empty";
	
    for(int i = 0; i < size; i++){
        if(array[i] == sb){
            for(int j = 0; i + j < size; j++)
                array[i+j] = array [i + j + 1];
            size--;
            break;
        }
    }

	// int index;
	// for (int i = 0; i < size; i++) {
	// 	if (array[i] == sb) {
	// 		index = i;
	// 		break;
	// 	}
	// }
	// for (int i = index; i < size; i++) {
	// 	array[i] = array[i + 1];
	// }
	// size--;
} 

void Collection::make_empty() {
	delete[] array;
	array = nullptr;
	size = 0;
	capacity = 0;
}

bool Collection::is_empty() const {
	return (size == 0);
}

int Collection::total_items() const {
	return size;
}

int Collection::total_items(Stress_ball_sizes s) const {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (array[i].get_size() == s)
			count++;
	}	
	return count;
}

int Collection::total_items(Stress_ball_colors c) const {
	int count = 0;
	for (int i = 0; i < this -> size; i++) {
		if (array[i].get_color() == c)
			count++;
	}
	return count;
}

void Collection::print_items() const {
	for (int i = 0; i < size; i++)
		cout << array[i] << endl;
}

Stress_ball& Collection::operator[](int i) {
	// if(i >= size)
	// 	throw "Exception: Error: i is out of range...";
	return array[i];

}

const Stress_ball& Collection::operator[](int i) const {
	// if(i >= size)
	// 	throw "Exception: Error: i is out of range...";
	return array[i];
}

istream& operator>>(istream& is, Collection& c) {
	std::string color, size;
	Stress_ball_colors co;
	Stress_ball_sizes si;
	while(is >> color >> size){
		//input for color
		if (color == "red")
			co = Stress_ball_colors::red;
		else if (color == "blue")
			co = Stress_ball_colors::blue;
		else if (color == "green")
			co = Stress_ball_colors::green;
		else if (color == "yellow")
			co = Stress_ball_colors::yellow;
		else
			cout << "Error: invalid input of color, please check your input..." << endl;
		//input for size
		if (size == "small")
			si = Stress_ball_sizes::small;
		else if (size == "medium")
			si = Stress_ball_sizes::medium;
		else if (size == "large")
			si = Stress_ball_sizes::large;
		else
			cout << "Error: invalid input of size, please check your input..." << endl;

		Stress_ball sb(co, si);
		c.insert_item(sb);
	}
	return is;
}

ostream& operator<<(ostream& os, const Collection& c) {
	for (int i = 0; i < c.total_items(); i++) {
		os << "(";
		switch (c[i].get_color()) {
			case Stress_ball_colors::red:
				os << "red, ";
				break;
			case Stress_ball_colors::blue:
				os << "blue, ";
				break;
			case Stress_ball_colors::yellow:
				os << "yellow, ";
				break;			
			case Stress_ball_colors::green:
				os << "green, ";
				break;
		}
		switch (c[i].get_size()) {
			case Stress_ball_sizes::small:
				os << "small)" << endl;
				break;
			case Stress_ball_sizes::medium:
				os << "medium)" << endl;
				break;
			case Stress_ball_sizes::large:
				os << "large)" << endl;
				break;
		}
	}
	return os;
}

Collection make_union(const Collection& c1, const Collection& c2) {
	Collection temp;
	for (int i = 0; i < c1.total_items(); i++)
		temp.insert_item(c1[i]);
	for (int j = 0; j < c2.total_items(); j++)
		temp.insert_item(c2[j]);
	return temp;
}

void swap(Collection& c1, Collection& c2) {
	Collection temp1 = move(c1);
	c1 = move(c2);
	c2 = move(temp1);
}

void sort_by_size(Collection& c, Sort_choice sort) {
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
			Stress_ball_sizes current;
			for (int i = 0; i < c.total_items(); i++) {
				preIndex = i - 1;
				current = c[i].get_size();
				Stress_ball temp = c[i];
				while (preIndex >= 0 && c[preIndex].get_size() > current) {
					c[preIndex + 1] = c[preIndex];
					preIndex--;
				}
				c[preIndex + 1] = temp;
			}
			break;
		case Sort_choice::selection_sort:
			int minIndex; 
			Stress_ball temp;
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