#include "header.h"

struct PersonInfo {
	string name;
	vector<string> numbers;
};

void print(const PersonInfo &info) {
	cout << info.name << ": ";
	for(auto a : info.numbers) {
		cout << a << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	string line, word; //will hold a line and word from input, respectively
	vector<PersonInfo> people; //will hold all hte records from the input
	std::istringstream record; 
	while(getline(cin, line)) {
		// The stream must be reset because after reading the first line, the
    	// stream's state is end-of-file, and calling `str(someString)` member
    	// function will not reset the stream's state. Thus, `clear()` must be
    	// called explicitly.
    	// However, the `open()` member funtion of `fstream` will automatically
    	// reset the stream's state if it succeeds.
		record.clear();
		//bind record to the line string
		record.str(line);
		PersonInfo person; //create an object to hols this record's data
		record >> person.name; //read the name
		while(record >> word) //read the phone numbers
			person.numbers.push_back(word); //and store them
		people.push_back(person); //append this record to people
	}

	for(auto a : people) 
		print(a);
	return 0;
}