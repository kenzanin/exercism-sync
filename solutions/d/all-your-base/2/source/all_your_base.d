module all_your_base;

import std.algorithm.mutation : reverse;
import std.bigint : BigInt;
import std.exception : enforce;

pure int[] rebase(int inputBase, immutable int[] digits, int outputBase)
{
    enforce(inputBase > 1);
    enforce(outputBase > 1);

    BigInt value = 0;
    foreach (digit; digits)
    {
        enforce(digit >= 0 && digit < inputBase);
        value = value * inputBase + digit;
    }

    if (value == 0)
    {
        return [0];
    }

    int[] result;
    while (value > 0)
    {
        result ~= cast(int)(value % outputBase);
        value /= outputBase;
    }

    result.reverse;
    return result;
}
