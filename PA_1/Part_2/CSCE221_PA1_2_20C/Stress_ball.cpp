/*
Name: Rong Xu
UIN: 928009312
Section: CSCE221-511
Project: PA1_part2
*/
#include "Stress_ball.h"

using namespace std;

// Default constructor
Stress_ball::Stress_ball() : color(Stress_ball_colors(rand() % 4)), size(Stress_ball_sizes(rand() % 3)) {}
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) : color(c), size(s) {}
// Destructor
// Stress_ball::~Stressball()

// Get color of the stress ball
Stress_ball_colors Stress_ball::get_color() const {
	return this -> color;
}

// Get size of the stress ball
Stress_ball_sizes Stress_ball::get_size() const {
	return this -> size;
}

// This operator will returns true if sb’s color and size are the same as
// color and size of the stress ball this (object calling the operator)
bool Stress_ball::operator==(const Stress_ball& sb) {
		return this -> get_color() == sb.get_color() && this -> get_size() == sb.get_size();
}


ostream& operator<<(std::ostream& o, const Stress_ball& sb) {
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
}