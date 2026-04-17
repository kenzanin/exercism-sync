module ocr_numbers;

pure string convert(immutable string[] rows)
{
    // Basic OCR digit recognition for 3x4 digit blocks.
    // Validate input dimensions
    if (rows.length % 4 != 0)
        throw new object.Exception("input rows not a multiple of 4");
    if (rows.length == 0)
        return "";

    size_t cols = rows[0].length;
    foreach (r; rows)
    {
        if (r.length != cols)
            throw new object.Exception("inconsistent row lengths");
    }
    if (cols % 3 != 0)
        throw new object.Exception("input columns not a multiple of 3");

    // Predefined patterns for digits 0-9 (concatenation of 4 rows of width 3)
    string[string] patterns;
    patterns[" _ " ~ "| |" ~ "|_|" ~ "   "] = "0";
    patterns["   " ~ "  |" ~ "  |" ~ "   "] = "1";
    patterns[" _ " ~ " _|" ~ "|_ " ~ "   "] = "2";
    patterns[" _ " ~ " _|" ~ " _|" ~ "   "] = "3";
    patterns["   " ~ "|_|" ~ "  |" ~ "   "] = "4";
    patterns[" _ " ~ "|_ " ~ " _|" ~ "   "] = "5";
    patterns[" _ " ~ "|_ " ~ "|_|" ~ "   "] = "6";
    patterns[" _ " ~ "  |" ~ "  |" ~ "   "] = "7";
    patterns[" _ " ~ "|_|" ~ "|_|" ~ "   "] = "8";
    patterns[" _ " ~ "|_|" ~ " _|" ~ "   "] = "9";

    string result;
    size_t rowGroups = rows.length / 4;
    size_t digitsPerRow = cols / 3;

    foreach (g; 0 .. rowGroups)
    {
        if (g != 0)
            result ~= ","; // separate groups with comma

        auto slice = rows[g * 4 .. g * 4 + 4];
        foreach (d; 0 .. digitsPerRow)
        {
            // build pattern for this digit
            string pat;
            foreach (r; 0 .. 4)
            {
                pat ~= slice[r][d * 3 .. d * 3 + 3];
            }
            if (pat in patterns)
                result ~= patterns[pat];
            else
                result ~= "?";
        }
    }

    return result;
}

unittest
{
    import std.exception : assertThrown;

    immutable int allTestsEnabled = 0;

    // Recognizes 0
    {
        immutable string[] rows = [
            " _ ",
            "| |",
            "|_|",
            "   ",
        ];
        assert(convert(rows) == "0");
    }

    static if (allTestsEnabled)
    {
        // Recognizes 1
        {
            immutable string[] rows = [
                "   ",
                "  |",
                "  |",
                "   ",
            ];
            assert(convert(rows) == "1");
        }

        // Unreadable but correctly sized inputs return ?
        {
            immutable string[] rows = [
                "   ",
                "  _",
                "  |",
                "   ",
            ];
            assert(convert(rows) == "?");
        }

        // Input with a number of lines that is not a multiple of four raises an error
        {
            immutable string[] rows = [
                " _ ",
                "| |",
                "   ",
            ];
            assertThrown(convert(rows));
        }

        // Input with a number of columns that is not a multiple of three raises an error
        {
            immutable string[] rows = [
                "    ",
                "   |",
                "   |",
                "    ",
            ];
            assertThrown(convert(rows));
        }

        // Recognizes 110101100
        {
            immutable string[] rows = [
                "       _     _        _  _ ",
                "  |  || |  || |  |  || || |",
                "  |  ||_|  ||_|  |  ||_||_|",
                "                           ",
            ];
            assert(convert(rows) == "110101100");
        }

        // Garbled numbers in a string are replaced with ?
        {
            immutable string[] rows = [
                "       _     _           _ ",
                "  |  || |  || |     || || |",
                "  |  | _|  ||_|  |  ||_||_|",
                "                           ",
            ];
            assert(convert(rows) == "11?10?1?0");
        }

        // Recognizes 2
        {
            immutable string[] rows = [
                " _ ",
                " _|",
                "|_ ",
                "   ",
            ];
            assert(convert(rows) == "2");
        }

        // Recognizes 3
        {
            immutable string[] rows = [
                " _ ",
                " _|",
                " _|",
                "   ",
            ];
            assert(convert(rows) == "3");
        }

        // Recognizes 4
        {
            immutable string[] rows = [
                "   ",
                "|_|",
                "  |",
                "   ",
            ];
            assert(convert(rows) == "4");
        }

        // Recognizes 5
        {
            immutable string[] rows = [
                " _ ",
                "|_ ",
                " _|",
                "   ",
            ];
            assert(convert(rows) == "5");
        }

        // Recognizes 6
        {
            immutable string[] rows = [
                " _ ",
                "|_ ",
                "|_|",
                "   ",
            ];
            assert(convert(rows) == "6");
        }

        // Recognizes 7
        {
            immutable string[] rows = [
                " _ ",
                "  |",
                "  |",
                "   ",
            ];
            assert(convert(rows) == "7");
        }

        // Recognizes 8
        {
            immutable string[] rows = [
                " _ ",
                "|_|",
                "|_|",
                "   ",
            ];
            assert(convert(rows) == "8");
        }

        // Recognizes 9
        {
            immutable string[] rows = [
                " _ ",
                "|_|",
                " _|",
                "   ",
            ];
            assert(convert(rows) == "9");
        }

        // Recognizes string of decimal numbers
        {
            immutable string[] rows = [
                "    _  _     _  _  _  _  _  _ ",
                "  | _| _||_||_ |_   ||_||_|| |",
                "  ||_  _|  | _||_|  ||_| _||_|",
                "                              ",
            ];
            assert(convert(rows) == "1234567890");
        }

        // Numbers separated by empty lines are recognized. Lines are joined by commas.
        {
            immutable string[] rows = [
                "    _  _ ",
                "  | _| _|",
                "  ||_  _|",
                "         ",
                "    _  _ ",
                "|_||_ |_ ",
                "  | _||_|",
                "         ",
                " _  _  _ ",
                "  ||_||_|",
                "  ||_| _|",
                "         ",
            ];
            assert(convert(rows) == "123,456,789");
        }
    }
}
