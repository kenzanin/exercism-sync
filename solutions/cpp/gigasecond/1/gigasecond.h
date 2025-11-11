#include <boost/date_time/posix_time/ptime.hpp>
#include <string>
#if !defined(GIGASECOND_H)
#define GIGASECOND_H
#include <boost/date_time/posix_time/ptime.hpp>

namespace gigasecond {
boost::posix_time::ptime advance(boost::posix_time::ptime test);
} // namespace gigasecond

#endif // GIGASECOND_H