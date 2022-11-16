#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <string>
#include <stdexcept>
#include <ostream>

#include "ISBN10.h"
#include "Date.h"
#include "Utility.h"

class Book {
private:
    std::string firstname_;
    std::string lastname_;
    std::string title_;
    ISBN10 isbn_;
    Date copyrightDate_;
public:

private:
    bool status_;
public:

    // getters
    ISBN10 getIsbn() const;

    std::string getTitle() const;

    std::string getFirstname() const;

    std::string getLastname() const;

    Date getCopyrightDate() const;

    // funzioni per registrare il prestito e la restituzione
    bool isLent() const;

    void lendBook();

    void returnBook();

    // setters

    void setIsbn(const ISBN10 &isbn);

    void setTitle(const std::string &title);

    void setFirstname(const std::string &firstname);

    void setLastname(const std::string &lastname);

    void setCopyrightDate(const Date &copyrightDate);
};

bool operator==(const Book &book, const Book &other);

bool operator!=(const Book &book, const Book &other);

std::ostream &operator<<(std::ostream &out, Book &book);

#endif //LIBRARY_BOOK_H
