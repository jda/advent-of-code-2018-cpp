// https://adventofcode.com/2018/day/2#part2
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iterator>  
#include <vector>

// given two strings of equal length, 
// return number of times they differ and string of common chars
std::pair<int, std::string> stringDiff(std::string boxOne, std::string boxTwo) {
    int difference = 0;
    std::string common = "";

    if (boxOne.length() != boxTwo.length()) {
        std::cerr << "invalid input, box label length not equal" << std::endl;
        return std::pair<int, std::string>(difference, common);
    }

    for (unsigned int i = 0; i < boxOne.length(); i++) {
        if (boxOne[i] == boxTwo[i]) {
            common += boxOne[i];
        } else {
            difference++;
        }
    }

    return std::pair<int, std::string>(difference, common);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <FILE>" << std::endl;
        return 1;
    }

    std::string infileName = argv[1];

    std::ifstream infile;
    infile.open(infileName);
    if (!infile.is_open()) {
        std::cerr << "Could not open file " << infileName << std::endl;
        return 1;
    }

    // load file as vector of boxes
    std::vector<std::string> boxes;
    std::string line;
    while (std::getline(infile, line)) {
        // skip blank
        if (line.empty()) {
            continue;
        }

        // skip commented
        if (line.rfind("#") == 0) {
            continue;
        }

        boxes.push_back(line);
    }
    infile.close();


    // process boxes
    for (auto box1: boxes) {
        for (auto box2: boxes) {
            std::pair<int, std::string> res = stringDiff(box1, box2);
            if (res.first == 1) {
                std::printf("Common box code: %s, chars: %i\n", res.second.c_str(), res.first);
                return 0;
            }
        }
    }

    return 1;
}