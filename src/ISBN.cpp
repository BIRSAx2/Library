#include "ISBN.h"

ISBN::ISBN() {}

ISBN::ISBN(std::string isbn) {

  originalIsbn_ = {isbn};

  for (char c : "-")
	isbn.erase(std::remove(isbn.begin(), isbn.end(), c), isbn.end());

  if (!IsValidIsbn(isbn))
	throw InvalidISBNException();

  normalizedIsbn_ = isbn;
}

bool ISBN::IsValidIsbn(std::string const &isbn) {

  std::string normalizedIsbn = isbn;

  for (char c : "-")
	normalizedIsbn.erase(std::remove(normalizedIsbn.begin(), normalizedIsbn.end(), c), normalizedIsbn.end());

  if (normalizedIsbn.length() != 10)
	return false;

  int sum = 0;
  int j = static_cast<int>(normalizedIsbn.size());

  for (int i = 0; i < normalizedIsbn.length() - 1; i++) {
	sum += (int)(normalizedIsbn[i] - '0') * j;
	j--;
  }


  char last = normalizedIsbn[9];


  if (last != 'X' && (last < '0' ||
					  last > '9'))
	return false;
  sum += ((last == 'X') ? ISBN10_SIZE :
						(last - '0'));

  return sum % 11 == 0;
}

void ISBN::SetIsbn(std::string isbn) {
  originalIsbn_ = isbn;
}

std::string ISBN::GetIsbn() const {
  return originalIsbn_;
}

std::string ISBN::GetNormalizedIsbn() const {
  return normalizedIsbn_;
}
ISBN &ISBN::operator=(const ISBN &other) {
  originalIsbn_ = other.GetIsbn();
  normalizedIsbn_ = other.GetNormalizedIsbn();
  return *this;
}

bool operator==(ISBN const &isbn, ISBN const &other) {
  return isbn.GetNormalizedIsbn() == other.GetNormalizedIsbn();
}

bool operator!=(ISBN const &isbn, ISBN const &other) {
  return !(isbn == other);
}

std::ostream &operator<<(std::ostream &out, ISBN const &other) {
  out << other.GetIsbn();
  return out;
}
