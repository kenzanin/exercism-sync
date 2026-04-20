module diamond;

pure string[] rows(char letter)
{
    import std.array : replicate;
    
    if (letter == 'A')
    {
        return ["A"];
    }

    int n = letter - 'A';
    string[] result;

    for (int i = 0; i <= n; i++)
    {
        char current = cast(char)('A' + i);
        int padding = n - i;
        string row;

        if (i == 0)
        {
            row = replicate(" ", padding) ~ "A" ~ replicate(" ", padding);
        }
        else
        {
            row = replicate(" ", padding) ~ current ~ replicate(" ", 2 * i - 1) ~ current ~ replicate(" ", padding);
        }
        result ~= row;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        char current = cast(char)('A' + i);
        int padding = n - i;
        string row = replicate(" ", padding) ~ current ~ replicate(" ", 2 * i - 1) ~ current ~ replicate(" ", padding);
        result ~= row;
    }

    result ~= replicate(" ", n) ~ "A" ~ replicate(" ", n);

    return result;
}

unittest
{
    immutable int allTestsEnabled = 0;

    // Degenerate case with a single 'A' row
    {
        string[] expected = ["A"];
        assert(rows('A') == expected);
    }

    static if (allTestsEnabled)
    {
        // Additional tests...
    }
}