#include "meetup.h"
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/gregorian/greg_month.hpp>

namespace meetup {
using boost::gregorian::months_of_year;
/*
fn last_day_in_month_and_year(day int, month int, year int) int {
        last_day_of_month := time.days_in_month(month, year) or { 0 }
        last_weekday_of_month := time.day_of_week(year, month,last_day_of_month)
        day_diff := day - last_weekday_of_month
        if day_diff > 0 {
                return last_day_of_month + day_diff - 7
        }
        return last_day_of_month + day_diff
}
*/
boost::gregorian::date last_day_in_month_and_year(int day, months_of_year month,
                                                  unsigned short int year) {
  boost::gregorian::date gre_date{year, month, 1};
  unsigned short int last_day_of_the_month =
      gre_date.end_of_month().day().as_number();
  unsigned short int last_weekday_of_the_month =
      gre_date.end_of_month().day_of_week().as_number();
  short int day_diff = day - last_weekday_of_the_month;
  unsigned short int date{};
  if (day_diff > 0) {
    date = last_day_of_the_month + day_diff - 7;
  } else {
    date = last_day_of_the_month + day_diff;
  }

  return boost::gregorian::date{year, month, date};
}

/*
fn nth_day_in_month_and_year(num int, day int, month int, year int) int {
        first_weekday_of_month := time.day_of_week(year, month, 1)
        day_diff := day - first_weekday_of_month
        if day_diff < 0 {
                return day_diff + 1 + num * 7
        } else {
                return day_diff + 1 + (num - 1) * 7
        }
}
*/

boost::gregorian::date nth_day_in_month_and_year(int num, int day,
                                                 months_of_year month,
                                                 unsigned short int year) {
  boost::gregorian::date gre_date{year, month, 1};
  auto day_diff = day - gre_date.day_of_week().as_number();
  unsigned short int date{};
  if (day_diff < 0) {
    date = day_diff + 1 + (num * 7);
  } else {
    date = day_diff + 1 + ((num - 1) * 7);
  }

  return boost::gregorian::date{year, month, date};
}

boost::gregorian::date
teen_date_helper(int n, unsigned short int year,
                 boost::gregorian::months_of_year month) {
  boost::gregorian::date gre_date{year, month, 13};
  auto day_of_thirteenth = gre_date.day_of_week();
  auto day_diff = n - day_of_thirteenth.as_number();
  short unsigned int date{};
  if (day_diff < 0) {
    date = 13 + (7 + day_diff);
  } else {
    date = 13 + day_diff;
  }
  return boost::gregorian::date{year, month, date};
}

boost::gregorian::date scheduler::monteenth(int n) const {
  return teen_date_helper(n, year, months);
}

boost::gregorian::date scheduler::first_monday(int n, int day) const {
  return nth_day_in_month_and_year(n, day, months, year);
}

boost::gregorian::date scheduler::last_monday(int day) const {
  return last_day_in_month_and_year(day, months, year);
}

} // namespace meetup
