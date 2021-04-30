/*
Name: Rong Xu
UIN: 928009312
Section: CSCE221-511
Project: PA1_part1
*/
#ifndef STRESSBALL
#define STRESSBALL

#include <iostream>
#include <cstdlib>
#include <sstream>

enum class Stress_ball_colors{red, blue, yellow, green};
enum class Stress_ball_sizes{small, medium, large};

class Stress_ball {

private:

	Stress_ball_colors color;
	Stress_ball_sizes size;

public:

	// Default constructor
	Stress_ball() : color(Stress_ball_colors(rand() % 4)), size(Stress_ball_sizes(rand() % 3)) {};
	Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) : color(c), size(s) {};

	// // Destructor
	// ~Stressball();

	// Get color of the stress ball
	Stress_ball_colors get_color() const {
		return this -> color;
	};

	// Get size of the stress ball
	Stress_ball_sizes get_size() const {
		return this -> size;
	};

	// This operator will returns true if sb’s color and size are the same as
	// color and size of the stress ball this (object calling the operator)
	bool operator==(const Stress_ball& sb) {
		return this -> get_color() == sb.get_color() && this -> get_size() == sb.get_size();
	};

};

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb) {
	o << "(";
	switch (sb.get_color()) {
		case Stress_ball_colors::red:
			o << "red, ";
			break;
		case Stress_ball_colors::blue:
			o << "blue, ";
			break;
		case Stress_ball_colors::yellow:
			o << "yellow, ";
			break;			
		case Stress_ball_colors::green:
			o << "green, ";
			break;
	}

	switch (sb.get_size()) {
		case Stress_ball_sizes::small:
			o << "small)";
			break;
		case Stress_ball_sizes::medium:
			o << "medium)";
			break;
		case Stress_ball_sizes::large:
			o << "large)";
			break;
	}

	return o;
};

#endif

///////////////test case 1 & 2///////////////

using namespace std;
int main() { 
	cout << "This is the test for PA1_part1 Stress_ball class" << endl << endl;

	cout << "Start building a random Stress_ball class object..." << endl;
	Stress_ball test1;
	cout << test1 << endl;

	cout << "Start building a specific Stress_ball class object..." << endl;
	Stress_ball test2(Stress_ball_colors::blue, Stress_ball_sizes::small);
	cout << test2 << endl;

	cout << "Check the \"==\" operator..." << endl;
	cout << (test1 == test2);


	return 0;
}