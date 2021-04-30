#include "Jeans.h"

using namespace std;

// Jeans_colors color;
// Jeans_sizes size;

Jeans::Jeans() : color(Jeans_colors(rand() % 4)), size(Jeans_sizes(rand() % 4)) {}
Jeans::Jeans(Jeans_colors c, Jeans_sizes s) : color(c), size(s) {}
Jeans_colors Jeans::get_color() const {return this -> color;}
Jeans_sizes Jeans::get_size() const {return this -> size;}
bool Jeans::operator==(const Jeans& sb) {
	return this -> get_color() == sb.get_color() && this -> get_size() == sb.get_size();
}

ostream& operator<<(ostream& o, const Jeans& sb) {
	// Jeans_colors {white, black, blue, grey};
	// Jeans_sizes {small, medium, large, xlarge};
	o << "(";
	switch (sb.get_color()) {
		case Jeans_colors::white:
			o << "white, ";
			break;
		case Jeans_colors::blue:
			o << "blue, ";
			break;
		case Jeans_colors::black:
			o << "black, ";
			break;			
		case Jeans_colors::grey:
			o << "grey, ";
			break;
	}

	switch (sb.get_size()) {
		case Jeans_sizes::small:
			o << "small)";
			break;
		case Jeans_sizes::medium:
			o << "medium)";
			break;
		case Jeans_sizes::large:
			o << "large)";
			break;
		case Jeans_sizes::xlarge:
			o << "xlarge)";
			break;
	}

	return o;
}