//implementation of record class

#include "Record.h"

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec) {
	std::string Blank, Title, Author, ISBN, Year, Edition;
	getline(is, Blank, '\n');
	getline(is,Title, '\n'); rec.setTitle(Title);
	getline(is,Author, '\n'); rec.setAuthor(Author);
	getline(is,ISBN, '\n'); rec.setISBN(ISBN);
	getline(is,Year, '\n'); rec.setYear(Year);
	getline(is,Edition, '\n'); rec.setEdition(Edition);
	return is;
};
std::ostream& operator<<(std::ostream& os, Record& rec) {
	os << rec.get_title() << std::endl;
	os << rec.get_author() << std::endl;
	os << rec.get_ISBN() << std::endl;
	os << rec.get_year() << std::endl;
	os << rec.get_edition() << std::endl;
	return os;
};

// Comparison operators
bool operator==(const Record& r1, const Record& r2) {
	return (r1.get_title() == r2.get_title() && r1.get_author() == r2.get_author() &&
		r1.get_ISBN() == r2.get_ISBN() && r1.get_year() == r2.get_year() && r1.get_edition() == r2.get_edition());
};