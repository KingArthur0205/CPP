#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;
using std::map;
using std::ifstream;

//Build the map from the given file
map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;
    string key, oneLine;
    while(map_file >> key && getline(map_file, oneLine)) {
        //If oneLine contains elements more than just a space, skip the first space
        if(oneLine.size() > 1)
            trans_map[key] = oneLine.substr(1);
        else
            throw std::runtime_error("Cannot find value for " + key);
    }
    return trans_map;
}

const string &transform(map<string, string> &trans_map, const string &word) {
    auto map_pos = trans_map.find(word);
    if(map_pos != trans_map.cend())
        return map_pos->second;
    return word;
}

void word_transform(ifstream &map_file, ifstream &input_file) {
    //build the map
    map<string, string> trans_map = buildMap(map_file);
    //Get each line by using the getline function
    string oneLine;
    while(std::getline(input_file, oneLine)) {
        //Create an istringstream object, linked to input_file
        std::istringstream stream(oneLine);
        string word;
        bool firstWord = true;
        //process each word
        while(stream >> word) {
            if(firstWord)
                firstWord = false;
            else
                std::cout << " ";
            //Call the transform function
            std::cout << transform(trans_map, word);
        }
        //Start a new line
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    std::ifstream map_file(argv[1]), input_file(argv[2]);
    word_transform(map_file, input_file);
    return 0;
}