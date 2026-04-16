module armstrong_numbers;

import std.conv : to;
import std.math : pow;

pure bool isArmstrongNumber(immutable int number)
{
    if (number < 0)
        return false;
    if (number < 10)
        return true;

    string s = to!string(number);
    size_t len = s.length;
    long sum = 0;

    foreach (char c; s)
    {
        sum += pow(cast(long)(c - '0'), cast(uint) len);
    }

    return sum == number;
}

unittest
{
    immutable int allTestsEnabled = 1;

    // Zero is an Armstrong number
    assert(isArmstrongNumber(0));

    static if (allTestsEnabled)
    {
        // Single digit numbers are Armstrong numbers
        assert(isArmstrongNumber(5));

        // There are no 2 digit Armstrong numbers
        assert(!isArmstrongNumber(10));

        // Three digit number that is an Armstrong number
        assert(isArmstrongNumber(153));

        // Three digit number that is not an Armstrong number
        assert(!isArmstrongNumber(100));

        // Four digit number that is an Armstrong number
        assert(isArmstrongNumber(9474));

        // Four digit number that is not an Armstrong number
        assert(!isArmstrongNumber(9475));

        // Seven digit number that is an Armstrong number
        assert(isArmstrongNumber(9926315));

        // Seven digit number that is not an Armstrong number
        assert(!isArmstrongNumber(9926314));
    }
}
