#include "utilities.h"

namespace util {
    // Credit to Evan Teran http://stackoverflow.com/questions/236129/split-a-string-in-c
    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
    bool validYear(const std::string &s) {
        if(s.length() == 0) {
            return false;
        }
        for(unsigned int i = 0; i < s.length(); i++) {
            if(!isdigit(s.at(i))) {
                return false;
            }
        }
        std::stringstream ss(s);
        int i;
        ss >> i;
        if(i < 1000 || i > 2015) {
            return false;
        }
        return true;
    }
    std::string stringToLower(std::string input) {
        std::string newString = "";
        for(unsigned int i = 0; i < input.size(); i++) {
            newString += tolower(input[i]);
        }
        return newString;
    }
}
