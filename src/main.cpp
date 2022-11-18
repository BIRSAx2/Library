#include <iomanip>
#include <iostream>

#include "Book.h"
#include "Date.h"
#include "ISBN.h"
#include "Utility.h"

using namespace std;

void testDateClass() {
  // Testing constructors and stream operators
  cout << "Testing constructors and << operator\n";
  Date date1 = Date{2022, 11, 16};
  Date date2 = Date{date1};

  //    Date SetDate = Date{};
  //    cout << "date1: " << date1 << '\n';
  cout << "date2 from date1: " << date2 << '\n';
  cout << "Date from string '2022-11-01': " << Date{"2022-11-01"} << '\n';
  //    cout << "date3: " << SetDate << '\n';

  // Testing setters

  cout << "\nTesting setters\n";
  date1.SetDay(01);
  cout << "SetDay(01): ";
  cout << date1 << '\n';

  date1.SetMonth(12);
  cout << "SetMonth(12): ";
  cout << date1 << '\n';

  date1.SetYear(2001);
  cout << "SetYear(2001): ";
  cout << date1 << '\n';

  date1.SetDate(2001, 02, 20);
  cout << "SetDate(2001,02,20): ";
  cout << date1 << '\n';

  // Testing getters
  cout << "\nTesting getters\n";
  cout << "SetDate: " << date1 << "\n";
  cout << "GetDay(): " << date1.GetDay() << "\n";
  cout << "GetMonth(): " << date1.GetMonth() << "\n";
  cout << "GetYear(): " << date1.GetYear() << "\n";

  // Testing toStringISO8601
  cout << "\nTesting to string conversions\n";

  cout << "ISO8601 format: " << date1 << '\n';

  // Testing static methods
  cout << "\nTesting to static methods\n";

  cout << "IsLeapYear(2022): " << (Date::IsLeapYear(2022) ? "true" : "false") << '\n';
  cout << "IsLeapYear(2004): " << (Date::IsLeapYear(2004) ? "true" : "false") << '\n';

  cout << "\nIsValidDate(-0001,01,01): " << (Date::IsValidDate(-1, 01, 01) ? "true" : "false") << '\n';
  cout << "IsValidDate(0001,01,01): " << (Date::IsValidDate(1, 01, 01) ? "true" : "false") << '\n';
  cout << "IsValidDate(2022,11,31): " << (Date::IsValidDate(2022, 11, 31) ? "true" : "false") << '\n';
  cout << "IsValidDate(2004,02,29): " << (Date::IsValidDate(2004, 02, 29) ? "true" : "false") << '\n';
  cout << "IsValidDate(2005,02,29): " << (Date::IsValidDate(2005, 02, 29) ? "true" : "false") << '\n';
  cout << "IsValidDate(2024,02,29): " << (Date::IsValidDate(2024, 02, 29) ? "true" : "false") << '\n';

  // Testing comparison operators
  try {
	Date valid_date = Date(2022, 11, 16);
	//        Date invalid_date = Date{2022, 15, 16};

	//        valid_date.SetYear(-1);

	//        valid_date.month(-1);

	//        valid_date.month(13);

	//        valid_date.GetDay(-1);
	//        valid_date.GetDay(40);

	//valid_date.month(2);
	//valid_date.GetDay(29);
  } catch (Date::InvalidDateException ex) {
	cout << "Exception thrown" << endl;
  }
}

void testISBN10Class() {

  // Testing constructors and getters
  // all the constructors will throw an exception if the argument passed is not a valid ISBN12/ISBN13
  cout << "\nTesting constructors and getters for ISBN version 10\n";

  string isbn = "007-462-542-X";
  cout << "Testing with a valid isbn but not normalized: " << isbn << endl;
  ISBN isbn10 = ISBN(isbn);
  cout << "\tDetected version: " << isbn10.GetVersion() << "\tParsed ISBN: " << isbn10.GetIsbn()
	   << "\tNormalized version: " << isbn10.GetNormalizedIsbn() << endl;

  string normalizedIsbn = "007462542X";
  cout << "Testing with a valid normalized version 10: " << normalizedIsbn << endl;
  ISBN isbn10FromNormalized = ISBN(normalizedIsbn);
  cout << "\tDetected version: " << isbn10FromNormalized.GetVersion() << "\tParsed ISBN: "
	   << isbn10FromNormalized.GetIsbn() << "\t\tNormalized version: " << isbn10FromNormalized.GetNormalizedIsbn()
	   << endl;

  cout << "\nTesting constructors and getters for ISBN version 10\n";

  string isbn13String = "978-17-3431-450-2";
  cout << "Testing with a valid isbn 13 but not normalized: " << isbn13String << endl;
  ISBN isbn13 = ISBN(isbn13String);
  cout << "\tDetected version: " << isbn13.GetVersion() << "\tParsed ISBN: " << isbn13.GetIsbn()
	   << "\tNormalized version: " << isbn13.GetNormalizedIsbn() << endl;

  string normalizedIsbn13 = "9781734314502";
  cout << "Testing with a valid normalized version 13: " << normalizedIsbn13 << endl;
  ISBN isbn13FromNormalized = ISBN(normalizedIsbn13);
  cout << "\tDetected version: " << isbn13FromNormalized.GetVersion() << "\tParsed ISBN: "
	   << isbn13FromNormalized.GetIsbn() << "\tNormalized version: " << isbn13FromNormalized.GetNormalizedIsbn()
	   << endl;

  // Testing setters
  cout << "\nTesting setters: \n";

  ISBN isbn1 = ISBN("9781734314502");
  cout << "Before SetIsbn(\"887-521-837-4\"): " << isbn1.GetIsbn() << endl;
  isbn1.SetIsbn("887-521-837-4");
  cout << "\tAfter : " << isbn1.GetIsbn() << endl;

  // Testing operators

  cout << "\nTesting comparison operators: \n";

  ISBN isbnA = ISBN("887-521-837-4");
  ISBN isbnB = ISBN("9781734314502");
  ISBN isbnC = ISBN("887-521-837-4");
  cout << isbnA << "==" << isbnB << ": " << ((isbnA == isbnB) ? "true" : "false") << endl;
  cout << isbnA << "==" << isbnC << ": " << ((isbnA == isbnC) ? "true" : "false") << endl;

  cout << isbnA << "!=" << isbnB << ": " << ((isbnA != isbnB) ? "true" : "false") << endl;
  cout << isbnA << "!=" << isbnC << ": " << ((isbnA != isbnC) ? "true" : "false") << endl;

  // Testing staic methods
  cout << "\nTesting static operators: \n";
  cout << "ISBN validation based on version\n";
  cout << "IsValidIsbn10(\"887-521-837-4\") : " << (ISBN::IsValidIsbn10("887-521-837-4") ? "true" : "false") << endl;
  cout << "IsValidIsbn13(\"887-521-837-4\") : " << (ISBN::IsValidIsbn13("887-521-837-4") ? "true" : "false") << endl;
  cout << "IsValidIsbn13(\"9781734314502\") : " << (ISBN::IsValidIsbn13("9781734314502") ? "true" : "false") << endl;
  cout << "IsValidIsbn10(\"9781734314502\") : " << (ISBN::IsValidIsbn10("9781734314502") ? "true" : "false") << endl;

  // invalid check digit
  cout << "Wrong check digit\n";
  cout << "IsValidIsbn10(\"887-521-837-9\") : " << (ISBN::IsValidIsbn10("887-521-837-9") ? "true" : "false") << endl;
  cout << "IsValidIsbn13(\"9781734314501\") : " << (ISBN::IsValidIsbn13("9781734314501") ? "true" : "false") << endl;

  // invalid format
  cout << "Wrong check size\n";

  cout << "IsValidIsbn10(\"87-521-837-4\") : " << (ISBN::IsValidIsbn10("87-521-837-4") ? "true" : "false") << endl;
  cout << "IsValidIsbn13(\"781734314502\") : " << (ISBN::IsValidIsbn13("781734314502") ? "true" : "false") << endl;
}

void testBookClass() {

  // Testing constructors

  Book a = Book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");

  ISBN isbn = {"0553573403"};
  Date date = {"1997-08-04"};

  Book b = Book("George", "R. R. Martin", "A Game of Thrones: A Song of Ice and Fire: Book One: 1", isbn, date);
  cout << "Book a: \n"
	   << a << endl;
  cout << "Book b: \n"
	   << b << endl;

  // Testing setters and getters
  cout << "\nTesting setters and getters:\n";

  cout << "Book a after \n"
		  "a.SetTitle(\"Title changed\")\n"
		  "a.SetFirstname(\"Firstname changed\")\n"
		  "a.SetLastname(\"Lastname changed\")\n"
		  "a.SetCopyrightDate(Date{\"2022-11-20\"})\n"
		  "a.SetIsbn(ISBN{\"007-462-542-X\"})"
		  ":\n";
  a.SetTitle("Title changed");
  a.SetLastname("Lastname changed");
  a.SetFirstname("Firstname changed");
  a.SetCopyrightDate(Date{"2022-11-20"});
  a.SetIsbn(ISBN{"007-462-542-X"});
  cout << a.GetTitle() << endl;
  cout << a.GetLastname() << endl;
  cout << a.GetFirstname() << endl;
  cout << a.GetCopyrightDate() << endl;
  cout << a.GetIsbn() << endl;

  // Testing lending functions

  cout << "\nTesting lending functions:\n";
  cout << "a.IsLent(): " << (a.IsLent() ? "true" : "false");
  a.LendBook();
  cout << "a.IsLent() after a.LendBook(): " << (a.IsLent() ? "true" : "false");

  try {
	cout << "\nTrying to lend a book already lent, should throw a BookAlreadyLentException\n";
	a.LendBook();

  } catch (BookAlreadyLentException &ex) {
	cout << "Catched Exception: " << ex.what() << endl;
  }

  a.ReturnBook();
  cout << "a.IsLent() after a.ReturnBook(): " << (a.IsLent() ? "true" : "false") << '\n';

  // Testing comparison operators
  cout << "\nTesting comparison operators:\n";

  cout << "Book a == Book b"
	   << " : " << (a == b ? "true" : "false") << '\n';
  cout << "Book a != Book b"
	   << " : " << (a != b ? "true" : "false") << '\n';
}

int main() {
  //  testDateClass();
  //    testISBN10Class();
  testBookClass();
  return 0;
}
