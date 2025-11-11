#include "sum_of_multiples.h"
#include <cstdint>
#include <vector>
#include "list"

namespace sum_of_multiples {
int to(std::vector<int> test, int test2)
{
    std::list<int> tmp{};
    std::uint32_t result{};
    for(auto a:test) {
        for(int i=a; i<test2; i+=a)
        {
            tmp.push_back(i);
        }
    }
    tmp.sort();
    tmp.unique();
    for(auto a:tmp)
    {
        result+=a;
    }

    return result;
}
}  // namespace sum_of_multiples
