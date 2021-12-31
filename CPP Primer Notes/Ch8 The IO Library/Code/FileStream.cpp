//Definition of Sales_data can be found in Ch7
//additional std:: scope operator might be needed
//additional head might be needed
#include "Sales_data.h"

int main(int argc, char *argv[]) {
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2], std::ofstream::app);
	if(!input)
		std::cerr << "No input" << endl;

	Sales_data temp;
	std::vector<Sales_data> vec;
	while(read(input, temp)) {
		Sales_data store = temp;
		vec.push_back(temp);
	}

	for(auto a : vec) {
		print(output, a) << endl;
	}
	return 0;
}