#include "Date.h"

bool Date::IsLeapYear(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0;
}

Date::Date() : year_{0},
			   month_{0},
			   day_{0} {}

bool Date::IsValidDate(int year, int month, int day) {
  // check SetYear
  if (year < 0)
	return false;

  // check month
  if (month < 1 || month > 12)
	return false;

  // check GetDay
  if (day < 1 || day > 31)
	return false;

  // check february correctness
  if (month == 2) {
	if (IsLeapYear(year))
	  return day <= 29;
	else
	  return day <= 28;
  }

  // other months
  if (month == 4 || month == 6 || month == 9 || month == 11)
	return day <= 30;

  return true;
}

// ISO8061:YYYY-MM-DD
bool Date::IsValidIso8061(const std::string &str) {
  if (str.length() != 10)
	return false;

  if (str[4] != '-' || str[7] != '-')
	return false;

  return true;
}

Date::Date(int year, int month, int day) : year_{year},
										   month_{month},
										   day_{day} {
  if (!IsValidDate(year, month, day))
	throw InvalidDateException();
}

Date::Date(const std::string &other) {
  if (!IsValidIso8061(other))
	throw InvalidDateException();

  int year, month, day;
  try {
	year = std::stoi(other.substr(0, 4));
	month = std::stoi(other.substr(5, 2));
	day = std::stoi(other.substr(8, 2));
  } catch (const std::exception &e) {
	throw InvalidDateException();
  }

  if (!IsValidDate(year, month, day))
	throw InvalidDateException();

  year_ = year;
  month_ = month;
  day_ = day;
}

Date::Date(const Date &other) : year_{other.year_},
								month_{other.month_},
								day_{other.day_} {}

void Date::SetDate(int year, int month, int day) {
  if (!IsValidDate(year, month, day))
	throw InvalidDateException();

  year_ = year;
  month_ = month;
  day_ = day;
}

void Date::SetYear(int year) {
  if (!IsValidDate(year, month_, day_))
	throw InvalidDateException();

  year_ = year;
}

void Date::SetMonth(int month) {
  if (!IsValidDate(year_, month, day_))
	throw InvalidDateException();

  month_ = month;
}

void Date::SetDay(int day) {
  if (!IsValidDate(year_, month_, day))
	throw InvalidDateException();

  day_ = day;
}

bool operator==(Date const &date, Date const &other) {
  return (date.GetYear() == other.GetYear() && date.GetMonth() == other.GetMonth() && date.GetDay() == other.GetDay());
}

bool operator!=(Date const &date, Date const &other) {
  return !(date == other);
}

std::ostream &operator<<(std::ostream &os, Date const &date) {
  return os << utility::padWithZeros(std::to_string(date.GetYear()), 4) << "-" << utility::padWithZeros(std::to_string(date.GetMonth()), 2)
			<< "-" << utility::padWithZeros(std::to_string(date.GetDay()), 2);
}
