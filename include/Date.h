#ifndef LIBRARY_DATE_H
#define LIBRARY_DATE_H

#include <string>
#include <iostream> // only for debug
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>

#include "Utility.h"

class Date {
private:
    int day_;
    int month_;
    int year_;

public:
    static constexpr int MONTH_LENGHTS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    static bool isLeapYear(int year);

    /*
 * Returns
 * <0 if date < other
 * =0 if date = other
 * >0 if date > other
 * */
    static int compareDates(Date const &date, Date const &other);

    static bool isValidDate(int year, int month, int day);

    // needed to overload unary operators
    static Date getNextDate(Date const &date);

    static Date getPreviousDate(Date const &date);

    Date();

    Date(const Date &other);

    Date(int year, int month, int day);

    Date(std::string dateISO8601);

    std::string toStringISO8601() const;

    int getDay() const {
        return day_;
    }

    int getMonth() const {
        return month_;
    }

    int getYear() const {
        return year_;
    }

    void setDate(int year, int month, int day);

    void setYear(int year);

    void setMonth(int month);

    void setDay(int day);

    // NB: To overload +,- it's better define Duration class to handle durations
    Date &operator=(Date const &other);

    Date &operator++();

    Date &operator--();

    Date &operator++(int); // postfix
    Date &operator--(int); // postfix


};

std::ostream &operator<<(std::ostream &os, Date const &date);

std::istream &operator>>(std::istream &in, Date const &date);

bool operator==(Date const &date, Date const &other);

bool operator!=(Date const &date, Date const &other);

bool operator>(Date const &date, Date const &other);

bool operator>=(Date const &date, Date const &other);

bool operator<(Date const &date, Date const &other);

bool operator<=(Date const &date, Date const &other);

// we could use an enumeration to represent weekdays and months
#endif //LIBRARY_DATE_H
