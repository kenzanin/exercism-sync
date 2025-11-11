#include "difference_of_squares.h"
#include <cmath>

namespace difference_of_squares {
    int sum_of_squares(int test){
        int var01{};
        for(int i=1;i<=test;i++)
        {
            var01+=std::pow(i,2);
        }
        return var01;
    }

    int square_of_sum(int test)
    {
        int var02{};
        for(int i=1;i<=test;i++){
            var02+=i;
        }
        return std::pow(var02,2);
    }

    int difference(int test)
    {
        return square_of_sum(test)-sum_of_squares(test);
    }
}  // namespace difference_of_squares
