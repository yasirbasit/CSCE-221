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
    // Record() : title(""), author(""), ISBN(""), year(""), edition("") {};
    // Record(std::string title, std::string author, std::string ISBN, std::string year, std::string edition) :
    // 	title(title), author(author), ISBN(ISBN), year(year), edition(edition) {};

    void set_title(std::string a);
    std::string get_title()const;

	void set_author(std::string a);
	std::string get_author()const;

	void set_ISBN(std::string a);
	std::string get_ISBN()const;

	void set_year(std::string a);
	std::string get_year()const;

	void set_edition(std::string a);
	std::string get_edition()const;
};

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, Record& rec);

// Comparison operators
bool operator==(const Record& r1, const Record& r2);
#endif