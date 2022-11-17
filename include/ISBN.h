#ifndef LIBRARY_ISBN_H
#define LIBRARY_ISBN_H

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

#include "Utility.h"

class ISBN {
private:
    static constexpr int ISBN10_SIZE = 10;
    static constexpr int ISBN13_SIZE = 13;

    int version_ = 10; // 10 o 13
    std::string originalIsbn_;
    std::string normalizedIsbn_; // without '-'

public:
    ISBN();
    ISBN(std::string isbn);

    void setIsbn(std::string isbn);

    int getVersion() const;

    std::string toString() const;
    std::string getNormalizedISBN() const;

    static bool isValidISBN10(std::string const &normalizedISBN10);

    static bool isValidISBN13(std::string const &isbn13);

    ISBN& operator=(ISBN const &other);

};


bool operator==(ISBN const &isbn10, ISBN const &other);

bool operator!=(ISBN const &isbn10, ISBN const &other);

bool operator<<(std::ostream &out, ISBN const &other);

#endif //LIBRARY_ISBN_H
