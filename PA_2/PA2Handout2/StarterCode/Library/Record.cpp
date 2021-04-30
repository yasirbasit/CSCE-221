//implementation of record class

#include "Record.h"

// Record() : title(""), author(""), ISBN(""), year(""), edition("") {}

// Record(std::string title, std::string author, std::string ISBN, std::string year, std::string edition) :
// 	title(title), author(author), ISBN(ISBN), year(year), edition(edition) {}

void Record::set_title(std::string a) {this -> title = a;}
std::string Record::get_title()const {return title;}

void Record::set_author(std::string a) {this -> author = a;}
std::string Record::get_author()const {return author;}

void Record::set_ISBN(std::string a) {this -> ISBN = a;}
std::string Record::get_ISBN()const {return ISBN;}

void Record::set_year(std::string a) {this -> year = a;}
std::string Record::get_year()const {return year;}

void Record::set_edition(std::string a) {this -> edition = a;}
std::string Record::get_edition()const {return edition;}

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec) {
	std::string Blank, Title, Author, ISBN, Year, Edition;
	getline(is, Blank, '\n');
	getline(is,Title, '\n'); rec.set_title(Title);
	getline(is,Author, '\n'); rec.set_author(Author);
	getline(is,ISBN, '\n'); rec.set_ISBN(ISBN);
	getline(is,Year, '\n'); rec.set_year(Year);
	getline(is,Edition, '\n'); rec.set_edition(Edition);
	return is;
}
std::ostream& operator<<(std::ostream& os, Record& rec) {
	os << rec.get_title() << std::endl;
	os << rec.get_author() << std::endl;
	os << rec.get_ISBN() << std::endl;
	os << rec.get_year() << std::endl;
	os << rec.get_edition() << std::endl;
	return os;
}

// Comparison operators
bool operator==(const Record& r1, const Record& r2) {
	return (r1.get_title() == r2.get_title() && 
		r1.get_author() == r2.get_author() &&
		r1.get_ISBN() == r2.get_ISBN());
}