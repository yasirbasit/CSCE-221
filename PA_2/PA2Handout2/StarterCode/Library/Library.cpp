#include "Library.h"
#include "TemplatedDLList.h"
#include <fstream>
#include <string>

using namespace std;

//Searches for a title in the database and returns vector of matching records
std::vector<Record> Library::search(std::string title) {
	vector<Record> temp;
	int index = title[0] - 'A';
	if(index < 0 || index > 25)
		return temp;
	else if(book_db.at(index).is_empty())
		return temp;
	else {
		DLListNode<Record>* n = book_db.at(index).first_node();
		while (n != book_db.at(index).after_last_node()) {
			if(title == n -> obj.get_title())
				temp.push_back(n -> obj);
			n = n -> next;
		}
	}
	return temp;
}

//Imports records from a file.  Does not import duplicates.
// Return the number of records added to the database
int Library::import_database(std::string filename) {
	string title, author, ISBN, year, edition;
	int num = 0;
	std::ifstream inFS(filename);
	Record temp;
	while(inFS >> temp) {
		int index = temp.get_title()[0] - 'A';
		book_db.at(index).insert_last(temp);
		num++;
	}
	inFS.close();
	return num;
}

//Exports the current database to a file
//Return the number of records exported
int Library::export_database(std::string filename) {
	int num = 0;
	std::ofstream outFS (filename);
	for (int i = 0; i < 26; i++) {
		DLListNode<Record>* n = book_db.at(i).first_node();
		while (n != book_db.at(i).after_last_node()) {
			outFS << n -> obj;
			num += 1;
			n = n -> next;
		}
	}
	outFS.close();
	return num;
}

void Library::print_database() {
	for (int i = 0; i < 26; i++) {
        DLListNode<Record>* header_node = book_db.at(i).first_node();
        while(header_node != book_db.at(i).after_last_node()){
            cout << header_node -> obj << endl;
            header_node = header_node -> next;
		}
	}
}

//add record to database, avoid complete duplicates
bool Library::add_record(Record book) {
	vector<Record> search_result;
    search_result = search(book.get_title());
	int index = book.get_title()[0] - 'A';
    if(search_result.size() == 0 && index < 25 && index > 0) {
    	book_db.at(index).insert_last(book);
		return true;
    }
    return false;
}

//Deletes a record from the database
void Library::remove_record(Record book) {
	int index = book.get_title()[0] - 'A';
	for (DLListNode<Record>* n = book_db.at(index).first_node(); n != book_db.at(index).after_last_node() -> next; n = n -> next) {
		if (n -> obj == book) {
			n = n -> next;
			book_db[index].remove_before(*n);
			break;
		}
	}
}

//Prompts user for yes or no and returns choice Y or N
char Library::prompt_yes_no() {
	cout << "Please Enter Y/N" << endl;
	char if_prompt;
	cin >> if_prompt;
	return if_prompt;
}
//Given a vector of menu options returns index of choice
int Library::prompt_menu(std::vector<std::string> a) {
	cout << "Please select an option" << endl;
	for (int i = 0; i < a.size(); i++)
		cout << i + 1 << ". " << a.at(i) << endl;
	int b;
	cin >> b;
	return b - 1;
}

//Prompts user for a new record
Record Library::prompt_record() {
	Record new_record;
	cout << "\n Please enter the title:" << endl;
	std::string title; getline(cin,title); new_record.set_title(title);
	cout << "\n Please enter the author:" << endl;
	std::string author; getline(cin,author); new_record.set_author(author);
	cout << "\n Please enter the ISBN:" << endl;
	std::string ISBN; getline(cin,ISBN); new_record.set_ISBN(ISBN);
	cout << "\n Please enter the year:" << endl;
	std::string year; getline(cin,year); new_record.set_year(year);
	cout << "\n Please enter the edition:" << endl;
	std::string edition; getline(cin,edition); new_record.set_edition(edition);
	return new_record; 
}

//Prompt for a valid title
std::string Library::prompt_title() {
	std::string prompt_title;
    getline(cin, prompt_title);
	return prompt_title;
}

// Prompt for a valid string
std::string Library::prompt_string(std::string prompt) {
	cout << prompt << endl;
	std::string usr_input;
	getline(cin, usr_input);
	return usr_input;
}