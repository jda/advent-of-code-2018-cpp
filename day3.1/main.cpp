// https://adventofcode.com/2018/day/3
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

struct Claim {
    int ID;
    
    int PositionTop;
    int PositionLeft;

    int Width;
    int Height;
};

Claim lineToClaim(std::string line) {
    Claim c = {};

    return c;
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

    // load file as vector of Claims
    std::vector<Claim> claims;
    std::string line;
    while (std::getline(infile, line)) {
        // skip blank
        if (line.empty()) {
            continue;
        }

        Claim claim = lineToClaim(line);
        claims.push_back(claim);
    }
    infile.close();


    return 1;
}