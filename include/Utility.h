#ifndef LIBRARY_UTILITY_H
#define LIBRARY_UTILITY_H

#include <string>
#include <vector>
#include <algorithm>

// helper functions
std::vector<std::string> split(std::string s, std::string delimiter);

bool isNumber(std::string str);

std::string padWithZeros(const std::string &str, int size);

#endif //LIBRARY_UTILITY_H
