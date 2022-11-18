#ifndef LIBRARY_DATE_H
#define LIBRARY_DATE_H

#include <iostream>
#include <string>

#include "Utility.h"

class Date {
 private:
  int day_;
  int month_;
  int year_;

 public:
  // Exception
  class InvalidDateException {};

  // helper functions
  static bool IsLeapYear(int year);
  static bool IsValidDate(int year, int month, int day);
  static bool IsValidIso8061(const std::string &str);

  // constructors
  Date(int year, int month, int day);
  Date(const std::string &other);
  Date(const Date &other);
  Date();

  // getters
  int GetDay() const {
	return day_;
  }
  int GetMonth() const {
	return month_;
  }
  int GetYear() const {
	return year_;
  }

  // setters
  void SetDate(int year, int month, int day);
  void SetDay(int day);
  void SetMonth(int month);
  void SetYear(int year);
};

// operators
std::ostream &operator<<(std::ostream &os, Date const &date);
bool operator==(Date const &date, Date const &other);
bool operator!=(Date const &date, Date const &other);

#endif// LIBRARY_DATE_H
#pragma clang diagnostic pop