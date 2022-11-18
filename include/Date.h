#ifndef LIBRARY_DATE_H
#define LIBRARY_DATE_H

#include "Utility.h"
#include <iostream>
#include <string>

#include <ctime>

class Date {
 private:
  int day_;
  int month_;
  int year_;

 public:
  // Exception
  class InvalidDateException {
  };

  // helper functions
  static bool isLeapYear(int year);

  static bool isValidDate(int year, int month, int day);

  static bool isValidISO8061(const std::string &str);

  // constructors
  Date(int year, int month, int day);

  Date(const std::string &other);

  Date(const Date &other);

  Date();

  // getter
  int day() const { return day_; }

  int month() const { return month_; }

  int year() const { return year_; }

  // setter
  void setDate(int year, int month, int day);

  void setYear(int year);

  void setMonth(int month);

  void setDay(int day);
};

// operators
std::ostream &operator<<(std::ostream &os, Date const &date);

bool operator==(Date const &date, Date const &other);

bool operator!=(Date const &date, Date const &other);

#endif//LIBRARY_DATE_H