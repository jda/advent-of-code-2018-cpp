// https://adventofcode.com/2018/day/2
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iterator>  

// given a string, return pair of number of letters that appear exactly two times
// and exactly three times.
std::pair<bool, bool> getDupeCount(std::string input) {
    std::unordered_map<char, int> letterCount;

    // count letters
    for (auto c: input) {
        letterCount[c]++;
    }

    // get counts
    bool twice = false;
    bool thrice = false;

    for (auto count: letterCount) {
        if (count.second == 2) {
            twice = true;
        } else if (count.second == 3) {
            thrice = true;
        }

        // no need to keep looping if both hit true
        if (twice == true && thrice == true) {
            break;
        }
    }

    return std::pair<bool, bool>(twice, thrice);
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

    std::string line;
    int twice = 0;
    int thrice = 0;
    while (std::getline(infile, line)) {
        // skip blank
        if (line.empty()) {
            continue;
        }

        // skip commented
        if (line.rfind("#") == 0) {
            continue;
        }

        std::pair<int, int> res = getDupeCount(line);

        twice += res.first;
        thrice += res.second;
    }
    infile.close();

    int checksum = twice * thrice;
    std::printf("Checksum: %i, Twice: %i, Thrice: %i\n", checksum, twice, thrice);
}