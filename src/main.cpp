#include <iostream>
#include <iomanip>
#include <regex>
#include "Date.h"
#include "ISBN.h"
#include "Utility.h"

using namespace std;

void testDateClass() {
    // Testing constructors and stream operators
    cout << "Testing constructors and << operator\n";
    Date date1 = Date{2022, 11, 16};
    Date date2 = Date{date1};
    cout << "date1: " << date1 << '\n';
    cout << "date2 from date1: " << date2 << '\n';
    cout << "date from string '2022/11/01': " << Date{"2022/11/1"} << '\n';


    // Testing setters

    cout << "\nTesting setters\n";
    date1.setDay(01);
    cout << "setDay(01): ";
    cout << date1 << '\n';

    date1.setMonth(12);
    cout << "setMonth(12): ";
    cout << date1 << '\n';

    date1.setYear(2001);
    cout << "setYear(2001): ";
    cout << date1 << '\n';

    date1.setDate(2001, 02, 20);
    cout << "setDate(2001,02,20): ";
    cout << date1 << '\n';

    // Testing getters
    cout << "\nTesting getters\n";
    cout << "date: " << date1 << "\n";
    cout << "getDay(): " << date1.getDay() << "\n";
    cout << "getMonth(): " << date1.getMonth() << "\n";
    cout << "getYear(): " << date1.getYear() << "\n";


    // Testing toStringISO8601
    cout << "\nTesting to string conversions\n";

    cout << "ISO8601 format: " << date1.toStringISO8601() << '\n';

    // Testing static methods
    cout << "\nTesting to static methods\n";

    cout << "isLeapYear(2022): " << (Date::isLeapYear(2022) ? "true" : "false") << '\n';
    cout << "isLeapYear(2004): " << (Date::isLeapYear(2004) ? "true" : "false") << '\n';

    cout << "\nisValidDate(-0001,01,01): " << (Date::isValidDate(-1, 01, 01) ? "true" : "false") << '\n';
    cout << "isValidDate(0001,01,01): " << (Date::isValidDate(1, 01, 01) ? "true" : "false") << '\n';
    cout << "isValidDate(2022,11,31): " << (Date::isValidDate(2022, 11, 31) ? "true" : "false") << '\n';
    cout << "isValidDate(2004,02,29): " << (Date::isValidDate(2004, 02, 29) ? "true" : "false") << '\n';
    cout << "isValidDate(2005,02,29): " << (Date::isValidDate(2005, 02, 29) ? "true" : "false") << '\n';
    cout << "isValidDate(2024,02,29): " << (Date::isValidDate(2024, 02, 29) ? "true" : "false") << '\n';
    cout << "\ngetNextDate (2022,11,16): " << Date::getNextDate(Date{2022, 11, 16}) << '\n';
    cout << "getPreviousDate (2022,11,16): " << Date::getPreviousDate(Date{2022, 11, 16}) << '\n';
    cout << "getPreviousDate (2022,11,01): " << Date::getPreviousDate(Date{2022, 11, 01}) << '\n';
    cout << "getPreviousDate (2022,01,01): " << Date::getPreviousDate(Date{2022, 01, 01}) << '\n';
    cout << "getNextDate (2021,12,31): " << Date::getNextDate(Date{2021, 12, 31}) << '\n';
    cout << "getNextDate (2022,02,28): " << Date::getNextDate(Date{2022, 02, 28}) << '\n';

    cout <<
         "\nCompareDates(date, other) returns:\n"
         "<0 if date < other\n"
         "=0 if date = other\n"
         ">0 if date > other\n";

    cout << "compareDates({2022,02,28}, {2022, 02, 27}): " << Date::compareDates({2022, 02, 28}, {2022, 02, 27})
         << '\n';
    cout << "compareDates({2022,02,27}, {2022, 02, 27}): " << Date::compareDates({2022, 02, 27}, {2022, 02, 27})
         << '\n';
    cout << "compareDates({2022,01,26}, {2022, 02, 27}): " << Date::compareDates({2022, 02, 26}, {2022, 02, 27})
         << '\n';

    // Testing unary operators
    cout << "\nTesting unary operators \n";
    Date date3 = {2022, 01, 01};
    cout << "date3: " << date3 << '\n';
    cout << "++date3: " << ++date3 << '\n';
    date3 = {2022, 01, 01};
    cout << "--date3: " << --date3 << '\n';
    date3 = {2022, 01, 01};
    date3++;
    cout << "after date3++: " << date3 << '\n';
    date3 = {2022, 01, 01};
    date3--;
    cout << "after date3--: " << date3 << '\n';

    // Testing comparison operators

    cout << "\nTesting comparison operators\n";
    Date a = Date{2022, 11, 16};
    Date b = Date{2022, 11, 15};
    Date c = Date{2022, 11, 16};

    cout << a << " > " << b << ": " << ((a > b) ? "true" : "false") << '\n';
    cout << a << " < " << b << ": " << ((a < b) ? "true" : "false") << '\n';
    cout << a << " >= " << b << ": " << ((a >= b) ? "true" : "false") << '\n';
    cout << a << " <= " << b << ": " << ((a <= b) ? "true" : "false") << '\n';
    cout << a << " <= " << c << ": " << ((a <= c) ? "true" : "false") << '\n';
    cout << a << " >= " << c << ": " << ((a >= c) ? "true" : "false") << '\n';
    cout << a << " == " << c << ": " << ((a == c) ? "true" : "false") << '\n';
    // Testing exceptions, uncomment one line at a time
    try {
        Date valid_date = Date(2022, 11, 16);
//        Date invalid_date = Date{2022, 15, 16};

//        valid_date.setYear(-1);

//        valid_date.setMonth(-1);

//        valid_date.setMonth(13);

//        valid_date.setDay(-1);
//        valid_date.setDay(40);

//valid_date.setMonth(2);
//valid_date.setDay(29);
    } catch (std::invalid_argument ex) {
        cout << ex.what();
    }


}

void testISBN10Class() {


// Testing constructors and getters
    // all the constructors will throw an exception if the argument passed is not a valid ISBN12/ISBN13
    cout << "\nTesting constructors and getters for ISBN version 10\n";

    string isbn = "007-462-542-X";
    cout << "Testing with a valid isbn but not normalized: " << isbn << endl;
    ISBN isbn10 = ISBN(isbn);
    cout << "\tDetected version: " << isbn10.getVersion() << "\tParsed ISBN: " << isbn10.getISBN()
         << "\tNormalized version: " << isbn10.getNormalizedISBN() << endl;


    string normalizedIsbn = "007462542X";
    cout << "Testing with a valid normalized version 10: " << normalizedIsbn << endl;
    ISBN isbn10FromNormalized = ISBN(normalizedIsbn);
    cout << "\tDetected version: " << isbn10FromNormalized.getVersion() << "\tParsed ISBN: "
         << isbn10FromNormalized.getISBN() << "\t\tNormalized version: " << isbn10FromNormalized.getNormalizedISBN()
         << endl;

    cout << "\nTesting constructors and getters for ISBN version 10\n";

    string isbn13String = "978-17-3431-450-2";
    cout << "Testing with a valid isbn 13 but not normalized: " << isbn13String << endl;
    ISBN isbn13 = ISBN(isbn13String);
    cout << "\tDetected version: " << isbn13.getVersion() << "\tParsed ISBN: " << isbn13.getISBN()
         << "\tNormalized version: " << isbn13.getNormalizedISBN() << endl;


    string normalizedIsbn13 = "9781734314502";
    cout << "Testing with a valid normalized version 13: " << normalizedIsbn13 << endl;
    ISBN isbn13FromNormalized = ISBN(normalizedIsbn13);
    cout << "\tDetected version: " << isbn13FromNormalized.getVersion() << "\tParsed ISBN: "
         << isbn13FromNormalized.getISBN() << "\tNormalized version: " << isbn13FromNormalized.getNormalizedISBN()
         << endl;


// Testing setters
    cout << "\nTesting setters: \n";

    ISBN isbn1 = ISBN("9781734314502");
    cout << "Before setIsbn(\"887-521-837-4\"): " << isbn1.getISBN() << endl;
    isbn1.setIsbn("887-521-837-4");
    cout << "\tAfter : " << isbn1.getISBN() << endl;

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
    cout << "isValidISBN10(\"887-521-837-4\") : " << (ISBN::isValidISBN10("887-521-837-4") ? "true" : "false") << endl;
    cout << "isValidISBN13(\"887-521-837-4\") : " << (ISBN::isValidISBN13("887-521-837-4") ? "true" : "false") << endl;
    cout << "isValidISBN13(\"9781734314502\") : " << (ISBN::isValidISBN13("9781734314502") ? "true" : "false") << endl;
    cout << "isValidISBN10(\"9781734314502\") : " << (ISBN::isValidISBN10("9781734314502") ? "true" : "false") << endl;

    // invalid check digit
    cout << "Wrong check digit\n";
    cout << "isValidISBN10(\"887-521-837-9\") : " << (ISBN::isValidISBN10("887-521-837-9") ? "true" : "false") << endl;
    cout << "isValidISBN13(\"9781734314501\") : " << (ISBN::isValidISBN13("9781734314501") ? "true" : "false") << endl;

    // invalid format
    cout << "Wrong check size\n";

    cout << "isValidISBN10(\"87-521-837-4\") : " << (ISBN::isValidISBN10("87-521-837-4") ? "true" : "false") << endl;
    cout << "isValidISBN13(\"781734314502\") : " << (ISBN::isValidISBN13("781734314502") ? "true" : "false") << endl;

}

void testBookClass() {

    // Testing constructors

    // Testing setters

    // Testing getters

    // Testing lending functions

    // Testing operators
}

int main() {
//    testDateClass();
    testISBN10Class();
//    testBookClass();
    return 0;
}
