#include "armstrong_numbers.h"
#include <cmath>
#include <cstdint>
#include <string>

namespace armstrong_numbers {
bool is_armstrong_number(std::uint32_t test)
{
    if(test<10)return true;
    std::string tmp=std::to_string(test);

    std::uint32_t tmp2{};
    for(auto &n:tmp)
    {
        int base=n-'0';
        tmp2+=pow(base,tmp.size());
    }
    return tmp2==test?true:false;
}
}  // namespace armstrong_numbers
