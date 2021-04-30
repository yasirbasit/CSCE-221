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
	Stress_ball();
	Stress_ball(Stress_ball_colors c, Stress_ball_sizes s);

	// // Destructor
	// ~Stressball();

	// Get color of the stress ball
	Stress_ball_colors get_color() const;

	// Get size of the stress ball
	Stress_ball_sizes get_size() const;

	// This operator will returns true if sb’s color and size are the same as
	// color and size of the stress ball this (object calling the operator)
	bool operator==(const Stress_ball& sb);

};

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb);

#endif