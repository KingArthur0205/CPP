#include "header.h"

istringstream &func(istringstream &input) {
	string word;
	while(input >> word)
		cout << word << endl;
	return input;
}


int main(int argc, char *argv[]) {
	string line;
	while(getline(cin, line)) {
		istringstream input(line);
		func(input);
	}
	return 0;
}
