#include "ISBN.h"

ISBN::ISBN() {}

ISBN::ISBN(std::string isbn) {

    originalIsbn_ = {isbn};

    isbn.erase(std::remove(isbn.begin(), isbn.end(), '-'), isbn.end());

    if (!IsValidIsbn10(isbn) && !IsValidIsbn13(isbn)) {
        throw std::invalid_argument("Invalid ISBN");
    }

    version_ = {static_cast<int>(isbn.size())};

    normalizedIsbn_ = {isbn};
}

void ISBN::SetIsbn(std::string isbn) {
    originalIsbn_ = {isbn};

    isbn.erase(std::remove(isbn.begin(), isbn.end(), '-'), isbn.end());

    if (!IsValidIsbn10(isbn) && !IsValidIsbn13(isbn)) {
        throw std::invalid_argument("Invalid ISBN");
    }

    version_ = {static_cast<int>(isbn.size())};

    normalizedIsbn_ = {isbn};
}

bool ISBN::IsValidIsbn10(std::string const &isbn) {

    std::string normalizedISBN10 = isbn;
    normalizedISBN10.erase(std::remove(normalizedISBN10.begin(), normalizedISBN10.end(), '-'), normalizedISBN10.end());

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

bool ISBN::IsValidIsbn13(const std::string &isbn13) {

    std::string normalizedIsbn13 = isbn13;
    normalizedIsbn13.erase(std::remove(normalizedIsbn13.begin(), normalizedIsbn13.end(), '-'), normalizedIsbn13.end());

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
    return isbn10.GetNormalizedIsbn() == other.GetNormalizedIsbn();
}

bool operator!=(const ISBN &isbn10, const ISBN &other) {
    return !(isbn10 == other);
}

std::ostream& operator<<(std::ostream &out, const ISBN &other) {
    out << other.GetIsbn();
    return out;
}

ISBN &ISBN::operator=(const ISBN &other) {
    version_ = other.GetVersion();
    originalIsbn_ = other.GetIsbn();
    normalizedIsbn_ = other.GetNormalizedIsbn();
    return *this;
}

int ISBN::GetVersion() const {
    return version_;
}


std::string ISBN::GetIsbn() const {
    return originalIsbn_;
}

std::string ISBN::GetNormalizedIsbn() const {
    return normalizedIsbn_;
}
