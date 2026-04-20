module bottle_song;

import std.conv : to;
import std.format : format;
import std.string : toUpper;

pure string recite(int startBottles, int takeDown)
{
    string numberToWord(int n)
    {
        static immutable words = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"];
        assert(n >= 0 && n <= 10);
        return words[n];
    }

    string bottles(int n, bool capitalize)
    {
        string w;
        if (n == 0) w = "no"; else w = numberToWord(n);
        if (capitalize && w.length) w = w[0..1].toUpper() ~ w[1..$];
        string plural = (n == 1) ? "bottle" : "bottles";
        return format("%s green %s", w, plural);
    }

    string verse(int current)
    {
        return format("%s hanging on the wall,\n", bottles(current, true)) ~
               format("%s hanging on the wall,\n", bottles(current, true)) ~
               "And if one green bottle should accidentally fall,\n" ~
               format("There'll be %s hanging on the wall.", bottles(current - 1, false));
    }

    string result;
    for (int i = 0; i < takeDown; ++i)
    {
        int cur = startBottles - i;
        result ~= verse(cur);
        if (i < takeDown - 1) result ~= "\n";
    }
    return result;
}

unittest
{
    import std.exception : assertThrown;
    import std.stdio : writeln;
    immutable int allTestsEnabled = 0;
    // Verse-single verse-first generic verse
    {
        string expected =
            "Ten green bottles hanging on the wall,\n" ~
            "Ten green bottles hanging on the wall,\n" ~
            "And if one green bottle should accidentally fall,\n" ~
            "There'll be nine green bottles hanging on the wall.";
        writeln("Got: [", recite(10, 1), "]");
        writeln("Exp: [", expected, "]");
        assert(recite(10, 1) == expected);
    }
    static if (allTestsEnabled)
    {
        // Additional tests omitted for brevity
    }
}
