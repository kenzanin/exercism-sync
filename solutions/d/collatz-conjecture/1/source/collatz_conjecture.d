module collatz_conjecture;

pure int steps(immutable int number)
{
    if (number <= 0)
    {
        throw new Exception("Number must be positive");
    }

    int count = 0;
    int current = number;

    while (current != 1)
    {
        if (current % 2 == 0)
        {
            current /= 2;
        }
        else
        {
            current = current * 3 + 1;
        }
        count++;
    }

    return count;
}

unittest
{
    import std.exception : assertThrown;

    const int allTestsEnabled = 0;

    // Zero steps for one
    assert(steps(1) == 0);

    static if (allTestsEnabled)
    {
        // Divide if even
        assert(steps(16) == 4);

        // Even and odd steps
        assert(steps(12) == 9);

        // Large number of even and odd steps
        assert(steps(1000000) == 152);

        // Zero is an error
        assertThrown(steps(0));

        // Negative value is an error
        assertThrown(steps(-15));
    }
}
