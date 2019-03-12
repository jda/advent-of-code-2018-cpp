// https://adventofcode.com/2018/day/1#part2
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <iterator>  

typedef std::unordered_set<int>::iterator SetIterator;

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

    // load file as vector of offsets
    std::string line;
    std::vector<int> offsets = {}; 
    while (std::getline(infile, line)) {
        // skip blank
        if (line.empty()) {
            continue;
        }

        // skip commented
        if (line.rfind("#") == 0) {
            continue;
        }

        int freqOffset = std::stoi(line.substr(1));
        if(line.front() == '-') {
            freqOffset *= -1;
        }

        offsets.push_back(freqOffset);
    }
    infile.close();

    // now we loop over offsets generating freq until we have dupes
    int offset = 0;
    std::unordered_set<int> seen = {};
    while(true) {
        for(int adj : offsets) {
            //std::cout << "offset: " << offset << " adj: " << adj << std::endl;
            offset += adj;

            std::pair<SetIterator, bool> res = seen.insert(offset);
            if (res.second == false) {
                std::cout << "found dupe: " << offset << std::endl;
                return 0;
            }
        } 
    }

}