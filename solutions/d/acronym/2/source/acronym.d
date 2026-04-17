module acronym;

import std.array : array;
import std.ascii : isAlpha, toUpper;
import std.algorithm : filter, map, splitter;
import std.conv : to;

string abbreviate(immutable string phrase)
{
    string result = "";
    bool nextIsStart = true;

    foreach (char c; phrase)
    {
        if (isAlpha(c) || c == '\'')
        {
            if (nextIsStart && isAlpha(c))
            {
                result ~= toUpper(c);
                nextIsStart = false;
            }
        }
        else
        {
            nextIsStart = true;
        }
    }

    return result;
}
