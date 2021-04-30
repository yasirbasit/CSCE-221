#ifndef Record_H
#define Record_H

#include <iostream>
#include <string>

class Record {
private:
    //member variables
    std::string title, author, ISBN, year, edition;
public:
    //accessor/mutator functions
    Record() : title(""), author(""), ISBN(""), year(""), edition("") {};
    Record(std::string title, std::string author, std::string ISBN, std::string year, std::string edition) :
    	title(title), author(author), ISBN(ISBN), year(year), edition(edition) {};

    void setTitle(std::string a) {title = a;};
    std::string get_title()const {return title;}

	void setAuthor(std::string a) {author = a;};
	std::string get_author()const {return author;}

	void setISBN(std::string a) {ISBN = a;};
	std::string get_ISBN()const {return ISBN;}

	void setYear(std::string a) {year = a;};
	std::string get_year()const {return year;}

	void setEdition(std::string a) {edition = a;};
	std::string get_edition()const {return edition;}
};

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, Record& rec);

// Comparison operators
bool operator==(const Record& r1, const Record& r2);
#endif