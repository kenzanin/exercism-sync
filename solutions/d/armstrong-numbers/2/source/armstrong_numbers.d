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
