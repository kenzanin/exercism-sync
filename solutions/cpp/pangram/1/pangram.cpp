#include "pangram.h"
#include <algorithm>
#include <cctype>
#include <string>
#include "algorithm"


namespace pangram {
bool is_pangram(std::string test)
{
    std::transform(test.begin(),test.end(),test.begin(),[](unsigned char c){return std::tolower(c);});
    for(char i='a'; i<='z'; i++)
    {
        if(!test.find(i))
            break;
    }
    return false;
}
}  // namespace pangram
