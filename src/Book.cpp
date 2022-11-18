#include "Book.h"

ISBN Book::GetIsbn() const {
    return isbn_;
}

std::string Book::GetTitle() const {
    return title_;
}

std::string Book::GetFirstname() const {
    return firstname_;
}

std::string Book::GetLastname() const {
    return lastname_;
}

Date Book::GetCopyrightDate() const {
    return copyrightDate_;
}

void Book::ReturnBook() {
    status_ = false;
}

bool Book::IsLent() const {
    return status_;
}

void Book::LendBook() {
    if (status_) throw BookAlreadyLentException();
    status_ = true;
}

void Book::SetIsbn(const ISBN &isbn) {
    isbn_ = isbn;
}

void Book::SetTitle(const std::string &title) {
    title_ = title;
}

void Book::SetFirstname(const std::string &firstname) {
    firstname_ = firstname;
}

void Book::SetLastname(const std::string &lastname) {
    lastname_ = lastname;
}

void Book::SetCopyrightDate(const Date &copyrightDate) {
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
    return out << book.GetTitle() << '\n' << book.GetFirstname() << " " << book.GetLastname() << "\n"
               << book.GetIsbn() << "\n"
               << book.GetCopyrightDate();
}

bool operator==(const Book &book, const Book &other) {
    return book.GetIsbn() == other.GetIsbn();
}

bool operator!=(const Book &book, const Book &other) {
    return !(book == other);
}



