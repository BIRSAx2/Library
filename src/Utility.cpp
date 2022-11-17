#include "Utility.h"

std::vector<std::string> split(std::string s, std::string delimiter) {
    int pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;

}

bool isNumber(std::string str) {
    return std::all_of(str.begin(), str.end(), [](char ch) { return std::isdigit(ch) != 0; });
}

std::string padWithZeros(const std::string &str, int size) {
    return std::string(size - std::min((int) str.size(), size), '0').append(str);
}

std::string replaceAll(std::string &str, char toBeReplace, char replacement) {
    std::replace(str.begin(), str.end(), toBeReplace, replacement);
}