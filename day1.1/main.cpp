#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

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

    long long int freq = 0;;
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

        std::string freqPart (line.substr(1));
        int freqOffset = std::stoi(freqPart);
        switch(line.front()) {
            case '+': 
                freq += freqOffset;
                break;
            case '-':
                freq -= freqOffset;
                break;
        }

    }
    infile.close();

    std::cout << "Offset: " << freq << std::endl;
}