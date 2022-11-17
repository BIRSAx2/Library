#include "ISBN.h"

ISBN::ISBN() {}

ISBN::ISBN(std::string isbn) {

    originalIsbn_ = {isbn};

    isbn.erase(std::remove(isbn.begin(), isbn.end(), '-'), isbn.end());

    if (!isValidISBN10(isbn) && !isValidISBN13(isbn)) {
        throw std::invalid_argument("Invalid ISBN");
    }

    version_ = {static_cast<int>(isbn.size())};

    normalizedIsbn_ = {isbn};
}

void ISBN::setIsbn(std::string isbn) {
    originalIsbn_ = {isbn};

    isbn.erase(std::remove(isbn.begin(), isbn.end(), '-'), isbn.end());

    if (!isValidISBN10(isbn) && !isValidISBN13(isbn)) {
        throw std::invalid_argument("Invalid ISBN");
    }

    version_ = {static_cast<int>(isbn.size())};

    normalizedIsbn_ = {isbn};
}

bool ISBN::isValidISBN10(std::string const &normalizedISBN10) {

    if (normalizedISBN10.size() != 10)
        return false;

    int sum = 0;
    int digit;
    for (int i = 0; i < ISBN10_SIZE - 1; i++) {
        digit = normalizedISBN10[i] - '0';
        if (0 > digit || 9 < digit)
            return false;
        sum += (digit * (ISBN10_SIZE - i));
    }

    char last = normalizedISBN10[9];

    if (last != 'X' && (last < '0' ||
                        last > '9'))
        return false;
    sum += ((last == 'X') ? ISBN10_SIZE :
            (last - '0'));

    return (sum % 11 == 0);
}

bool ISBN::isValidISBN13(const std::string &normalizedIsbn13) {
    if (normalizedIsbn13.size() != 13) return false;

    int sum = 0;
    int digit;
    for (int i = 0; i < normalizedIsbn13.size(); i++) {
        digit = normalizedIsbn13[i] - '0';
        if (digit < 0 || digit > 9) return false;
        sum += i % 2 == 0 ? digit : digit * 3;
    }
    return sum % 10 == 0;
}

bool operator==(const ISBN &isbn10, const ISBN &other) {
    return false;
}

bool operator!=(const ISBN &isbn10, const ISBN &other) {
    return false;
}

bool operator<<(std::ostream &out, const ISBN &other) {
    return false;
}

bool ISBN::operator=(const ISBN &other) {
    return false;
}

int ISBN::getVersion() const {
    return version_;
}


std::string ISBN::toString() {
    return originalIsbn_;
}

std::string ISBN::getNormalizedISBN() {
    return normalizedIsbn_;
}
