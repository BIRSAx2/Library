#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <string>
#include <stdexcept>
#include <ostream>

#include "ISBN.h"
#include "Date.h"
#include "Utility.h"

class Book {
private:
    std::string firstname_;
    std::string lastname_;
    std::string title_;
    ISBN isbn_;
    Date copyrightDate_;
public:

private:
    bool status_;
public:
    Book(const std::string &firstname, const std::string &lastname, const std::string &title);

    Book(const std::string &firstname, const std::string &lastname, const std::string &title, const std::string &isbn);
    Book(const std::string &firstname, const std::string &lastname, const std::string &title, const ISBN &isbn);

    Book(const std::string &firstname, const std::string &lastname, const std::string &title, const ISBN &isbn,
         const Date &copyrightDate);

    // getters
    ISBN getIsbn() const;

    std::string getTitle() const;

    std::string getFirstname() const;

    std::string getLastname() const;

    Date getCopyrightDate() const;

    // funzioni per registrare il prestito e la restituzione
    bool isLent() const;

    void lendBook();

    void returnBook();

    // setters

    void setIsbn(const ISBN &isbn);

    void setTitle(const std::string &title);

    void setFirstname(const std::string &firstname);

    void setLastname(const std::string &lastname);

    void setCopyrightDate(const Date &copyrightDate);
};

bool operator==(const Book &book, const Book &other);

bool operator!=(const Book &book, const Book &other);

std::ostream &operator<<(std::ostream &out, Book &book);


struct BookAlreadyLentException : public std::exception {
    std::string what_message;

    const char *what() const throw() {
        return "The book your are trying to lend is already lent";
    }
};

#endif //LIBRARY_BOOK_H
