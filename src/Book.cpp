#include "Book.h"

ISBN Book::getIsbn() const {
    return isbn_;
}

std::string Book::getTitle() const {
    return title_;
}

std::string Book::getFirstname() const {
    return firstname_;
}

std::string Book::getLastname() const {
    return lastname_;
}

Date Book::getCopyrightDate() const {
    return copyrightDate_;
}

void Book::returnBook() {
    status_ = false;
}

bool Book::isLent() const {
    return status_;
}

void Book::lendBook() {
    if (status_) throw BookAlreadyLentException();
    status_ = true;
}

void Book::setIsbn(const ISBN &isbn) {
    isbn_ = isbn;
}

void Book::setTitle(const std::string &title) {
    title_ = title;
}

void Book::setFirstname(const std::string &firstname) {
    firstname_ = firstname;
}

void Book::setLastname(const std::string &lastname) {
    lastname_ = lastname;
}

void Book::setCopyrightDate(const Date &copyrightDate) {
    copyrightDate_ = copyrightDate;
}

Book::Book(const std::string &firstname, const std::string &lastname, const std::string &title) :
        firstname_(firstname), lastname_(lastname), title_(title) {}

Book::Book(const std::string &firstname, const std::string &lastname, const std::string &title, const std::string &isbn)
        : firstname_(firstname), lastname_(lastname), title_(title), isbn_(isbn) {}

Book::Book(const std::string &firstname, const std::string &lastname, const std::string &title, const ISBN &isbn)
        : firstname_(firstname), lastname_(lastname), title_(title), isbn_(isbn) {}

Book::Book(const std::string &firstname, const std::string &lastname, const std::string &title, const ISBN &isbn,
           const Date &copyrightDate) :
        firstname_(firstname), lastname_(lastname), title_(title), isbn_(isbn), copyrightDate_(copyrightDate) {}


std::ostream &operator<<(std::ostream &out, Book &book) {
    return out << book.getTitle() << '\n' << book.getFirstname() << " " << book.getLastname() << "\n"
               << book.getIsbn() << "\n"
               << book.getCopyrightDate();
}

bool operator==(const Book &book, const Book &other) {
    return book.getIsbn() == other.getIsbn();
}

bool operator!=(const Book &book, const Book &other) {
    return !(book == other);
}



