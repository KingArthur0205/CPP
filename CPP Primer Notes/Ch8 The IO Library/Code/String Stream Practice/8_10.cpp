#include "header.h"


int main(int argc, char *argv[]) {
	ifstream inputFile(argv[1]);
	if(!inputFile)
		std::cerr << "Input Error" << endl;
	
	vector<string> lines;
	string line;
	while(getline(inputFile, line)) {
		lines.push_back(line);
	}

	cout << "Print out lines: " << endl;
	for(auto a : lines)
		cout << a << endl;

	vector<string> words;
	for(string singleLine: lines) {
		istringstream word(singleLine);
		string singleWord;
		while(word >> singleWord)
			words.push_back(singleWord);
	}

	cout << "Print out words:" << endl;
	for(auto a : words)
		cout << a << endl;
	return 0;
}