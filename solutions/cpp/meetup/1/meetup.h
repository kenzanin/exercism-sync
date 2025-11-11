#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/gregorian/greg_month.hpp>
#include <cstddef>
#if !defined(MEETUP_H)
#define MEETUP_H
#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {
class scheduler {
  boost::gregorian::months_of_year months{};
  short unsigned int year{};

public:
  scheduler(boost::gregorian::months_of_year months_of_year, std::size_t year)
      : months(months_of_year), year(year){};

  using gre_date = boost::gregorian::date;

  gre_date monteenth(int n = 1) const;
  gre_date tuesteenth() const { return monteenth(2); };
  gre_date wednesteenth() const { return monteenth(3); };
  gre_date thursteenth() const { return monteenth(4); };
  gre_date friteenth() const { return monteenth(5); };
  gre_date saturteenth() const { return monteenth(6); };
  gre_date sunteenth() const { return monteenth(0); };
  gre_date first_monday(int n = 1, int day = 1) const;
  gre_date first_tuesday() const { return first_monday(1, 2); };
  gre_date first_wednesday() const { return first_monday(1, 3); };
  gre_date first_thursday() const { return first_monday(1, 4); };
  gre_date first_friday() const { return first_monday(1, 5); }
  gre_date first_saturday() const { return first_monday(1, 6); }
  gre_date first_sunday() const { return first_monday(1, 0); }
  gre_date second_monday() const { return first_monday(2, 1); };
  gre_date second_tuesday() const { return first_monday(2, 2); };
  gre_date second_wednesday() const { return first_monday(2, 3); };
  gre_date second_thursday() const { return first_monday(2, 4); };
  gre_date second_friday() const { return first_monday(2, 5); }
  gre_date second_saturday() const { return first_monday(2, 6); }
  gre_date second_sunday() const { return first_monday(2, 0); }
  gre_date third_monday() const { return first_monday(3, 1); };
  gre_date third_tuesday() const { return first_monday(3, 2); };
  gre_date third_wednesday() const { return first_monday(3, 3); };
  gre_date third_thursday() const { return first_monday(3, 4); };
  gre_date third_friday() const { return first_monday(3, 5); }
  gre_date third_saturday() const { return first_monday(3, 6); }
  gre_date third_sunday() const { return first_monday(3, 0); }
  gre_date fourth_monday() const { return first_monday(4, 1); };
  gre_date fourth_tuesday() const { return first_monday(4, 2); };
  gre_date fourth_wednesday() const { return first_monday(4, 3); };
  gre_date fourth_thursday() const { return first_monday(4, 4); };
  gre_date fourth_friday() const { return first_monday(4, 5); }
  gre_date fourth_saturday() const { return first_monday(4, 6); }
  gre_date fourth_sunday() const { return first_monday(4, 0); }
  gre_date last_monday(int day = 1) const;
  gre_date last_tuesday() const { return last_monday(2); };
  gre_date last_wednesday() const { return last_monday(3); };
  gre_date last_thursday() const { return last_monday(4); };
  gre_date last_friday() const { return last_monday(5); }
  gre_date last_saturday() const { return last_monday(6); }
  gre_date last_sunday() const { return last_monday(0); }
};

} // namespace meetup

#endif // MEETUP_H