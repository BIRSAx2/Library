#include "ISBN10.h"

bool ISBN10::isValidISBN10Format(std::string isbn10) {
    return false;
}

ISBN10::ISBN10(const std::string &isbn10) {

}

ISBN10::ISBN10(int groupIdentifier, int publisherIdentifier, int titleIdentifier, int checkDigit) {

}

int ISBN10::getGroupIdentifier() const {
    return 0;
}

int ISBN10::getPublisherIdentifier() const {
    return 0;
}

int ISBN10::getTitleIdentifier() const {
    return 0;
}

int ISBN10::getCheckDigit() const {
    return 0;
}

bool ISBN10::isValidISBN() {
    return false;
}

ISBN10 &ISBN10::stringToISBN10(std::string isbn10) {
    std::vector<std::string> tokens = split(isbn10, "-");


}

int ISBN10::calculateCheckDigit() {
    return 0;
}

bool operator==(const ISBN10 &isbn10, const ISBN10 &other) {
    return false;
}

bool operator!=(const ISBN10 &isbn10, const ISBN10 &other) {
    return false;
}

bool operator<<(std::ostream &out, const ISBN10 &other) {
    return false;
}
