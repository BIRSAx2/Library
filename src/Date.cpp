#include "Date.h"

Date::Date(){
    year_ = 0;
    month_ = 0;
    day_ = 0;
}

Date::Date(int year, int month, int day) : day_(day), month_(month), year_(year) {
    if (!isValidDate(year, month, day)) throw std::invalid_argument("Invalid Date");
}

Date::Date(const Date &other) {
    year_ = other.year_;
    month_ = other.month_;
    day_ = other.day_;
}

Date::Date(std::string date) {
    std::vector<std::string> parsed = split(date, "/");

    if (parsed.size() != 3) throw std::invalid_argument("Invalid date format");
    for (std::string &s: parsed) {
        if (!isNumber(s)) throw std::invalid_argument("Invalid number format");
    }
    int year = std::stoi(parsed.at(0));
    int month = std::stoi(parsed.at(1));
    int day = std::stoi(parsed.at(2));

    if (!isValidDate(year, month, day)) throw std::invalid_argument("Invalid date");

    year_ = {year};
    month_ = {month};
    day_ = {day};

}

std::string Date::toStringISO8601() const {
    // lo standard ISO8601 definisce la data come yyyy/mm/dd

    std::string year = std::to_string(year_);
    std::string month = std::to_string(month_);
    std::string day = std::to_string(day_);
    // TODO: refactor this, extract the padding to a function
    return padWithZeros(year, 4) + "/"
           + padWithZeros(month, 2) + "/"
           + padWithZeros(day, 2);
}

void Date::setDate(int year, int month, int day) {
    if (!Date::isValidDate(year, month, day)) throw std::invalid_argument("Invalid Date");
    year_ = year;
    month_ = month;
    day_ = day;
}

void Date::setDay(int day) {
    if (!Date::isValidDate(year_, month_, day)) throw std::invalid_argument("Invalid day");
    day_ = day;
}

void Date::setMonth(int month) {
    if (!Date::isValidDate(year_, month, day_)) throw std::invalid_argument("Invalid month");
    month_ = month;
}

void Date::setYear(int year) {
    if (!Date::isValidDate(year, month_, day_)) throw new std::invalid_argument("Invalid year");
    year_ = year;
}

Date &Date::operator=(Date const &other) {
    day_ = other.getDay();
    month_ = other.getMonth();
    year_ = other.getYear();
    return *this;
}

// Comparisons
int Date::compareDates(Date const &date, Date const &other) {
    if (date.getYear() != other.getYear()) return date.getYear() - other.getYear();
    if (date.getMonth() != other.getMonth()) return date.getMonth() - other.getMonth();
    return date.getDay() - other.getDay();
}

bool operator<(Date const &date, Date const &other) {
    int comparison = Date::compareDates(date, other);
    return comparison < 0;
}

bool operator<=(Date const &date, Date const &other) {
    return date < other || date == other;
}

bool operator>(Date const &date, Date const &other) {
    int comparison = Date::compareDates(date, other);
    return comparison > 0;
}

bool operator>=(Date const &date, Date const &other) {
    return date > other || date == other;
}

bool operator==(Date const &date, Date const &other) {
    return Date::compareDates(date, other) == 0;
}

bool operator!=(Date const &date, Date const &other) {
    return !(date == other);
}

bool Date::isLeapYear(int year) {
    // Calendario Gregoriano
    return ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0;
}

bool Date::isValidDate(int year, int month, int day) {
    if (year < 0 || month > 12 || month < 1 || day < 1) return false;
    // check for leap year
    if (month == 2 && Date::isLeapYear(year) && day > Date::MONTH_LENGHTS[month] + 1) return false;

    if (!Date::isLeapYear(year) && day > Date::MONTH_LENGHTS[month]) return false;

    return true;
}

Date &Date::operator++() {
    Date date = *this;
    *this = getNextDate(date);
    return *this;
}

Date &Date::operator--() {
    Date date = *this;
    *this = getPreviousDate(date);
    return *this;
}

Date &Date::operator--(int) {
    Date date = *this;
    *this = getPreviousDate(date);
    return date;
}

Date &Date::operator++(int) {
    Date date = *this;
    *this = getNextDate(date);
    return date;
}

Date Date::getNextDate(const Date &date) {
    if (isValidDate(date.getYear(), date.getMonth(), date.getDay() + 1))
        return Date{date.getYear(), date.getMonth(), date.getDay() + 1};

    if (isValidDate(date.getYear(), date.getMonth() + 1, 1))
        return Date{date.getYear(), date.getMonth() + 1, 1};

    return Date{date.getYear() + 1, 1, 1};
}

Date Date::getPreviousDate(const Date &date) {

    if (isValidDate(date.getYear(), date.getMonth(), date.getDay() - 1))
        return Date{date.getYear(), date.getMonth(), date.getDay() - 1};
    if (date.getMonth() - 1 > 0 &&
        isValidDate(date.getYear(), date.getMonth() - 1, Date::MONTH_LENGHTS[date.getMonth() - 1]))
        return Date{date.getYear(), date.getMonth() - 1, Date::MONTH_LENGHTS[date.getMonth() - 1]};

    return Date{date.getYear() - 1, 12, 31};
}

std::ostream &operator<<(std::ostream &os, Date const &date) {
    return os << date.toStringISO8601();
}