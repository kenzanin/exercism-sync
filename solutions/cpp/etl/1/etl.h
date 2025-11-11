#include <vector>
#if !defined(ETL_H)
#define ETL_H
#include "map"
#include "vector"

namespace etl {
    std::map<char,int> transform(const std::map<int,std::vector<char>>);
}  // namespace etl

#endif // ETL_H