#ifndef LIBRARY_ISBN_H
#define LIBRARY_ISBN_H

#include <algorithm>
#include <iostream>
#include <string>

class ISBN {
 private:
  static constexpr int ISBN10_SIZE = 10;

  std::string originalIsbn_;
  std::string normalizedIsbn_;

 public:
  ISBN();
  ISBN(std::string isbn);

  void SetIsbn(std::string isbn);

  std::string GetIsbn() const;
  std::string GetNormalizedIsbn() const;

  static bool IsValidIsbn(std::string const &normalizedISBN);

  ISBN &operator=(ISBN const &other);

  class InvalidISBNException {};
};

bool operator==(ISBN const &isbn, ISBN const &other);

bool operator!=(ISBN const &isbn, ISBN const &other);

std::ostream &operator<<(std::ostream &out, ISBN const &other);

#endif//LIBRARY_ISBN_H