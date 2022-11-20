#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <ostream>
#include <stdexcept>
#include <string>

#include "Date.h"
#include "ISBN.h"
#include "Utility.h"

class Book {
 private:
  std::string firstname_;
  std::string lastname_;
  std::string title_;
  ISBN isbn_;
  Date copyrightDate_;
  bool available_;

 public:

  // it's doesn't make sense to create and empty book, but as of requirements by the professor we needed to implement an empty constructor in order to instantiate a vector with a size of 10
  Book();

  Book(Book const &book);

  Book(const std::string &firstname, const std::string &lastname, const std::string &title);

  Book(const std::string &firstname, const std::string &lastname, const std::string &title, const std::string &isbn);

  Book(const std::string &firstname, const std::string &lastname, const std::string &title, const ISBN &isbn);

  Book(const std::string &firstname, const std::string &lastname, const std::string &title, const ISBN &isbn,
	   const Date &copyrightDate);

  // getters
  ISBN GetIsbn() const;

  std::string GetTitle() const;

  std::string GetFirstname() const;

  std::string GetLastname() const;

  Date GetCopyrightDate() const;

  // funzioni per registrare il prestito e la restituzione
  bool IsLent() const;

  void LendBook();

  void ReturnBook();

  // setters

  void SetIsbn(const ISBN &isbn);

  void SetTitle(const std::string &title);

  void SetFirstname(const std::string &firstname);

  void SetLastname(const std::string &lastname);

  void SetCopyrightDate(const Date &copyrightDate);

  class BookAlreadyLentException : public std::exception {
	std::string what_message;

   public:
	const char *what() const throw() {
	  return "The book your are trying to lend is already lent";
	}
  };
};

bool operator==(const Book &book, const Book &other);

bool operator!=(const Book &book, const Book &other);

std::ostream &operator<<(std::ostream &out, Book &book);

#endif//LIBRARY_BOOK_H
