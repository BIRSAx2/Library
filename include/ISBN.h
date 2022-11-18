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

    void SetIsbn(std::string isbn);

    int GetVersion() const;

    std::string GetIsbn() const;
    std::string GetNormalizedIsbn() const;

    static bool IsValidIsbn10(std::string const &normalizedISBN10);

    static bool IsValidIsbn13(std::string const &isbn13);

    ISBN& operator=(ISBN const &other);


};


bool operator==(ISBN const &isbn10, ISBN const &other);

bool operator!=(ISBN const &isbn10, ISBN const &other);

std::ostream& operator<<(std::ostream &out, ISBN const &other);

#endif //LIBRARY_ISBN_H
