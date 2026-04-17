module bob;

import std.string : strip;

string hey(immutable string input)
{
    auto trimmed = strip(input);

    // Empty or whitespace only
    if (trimmed.length == 0)
    {
        return "Fine. Be that way!";
    }

    bool isUpper = true;
    bool hasLetter = false;

    foreach (c; trimmed)
    {
        if (c >= 'a' && c <= 'z')
        {
            hasLetter = true;
            isUpper = false;
            break;
        }
        if (c >= 'A' && c <= 'Z')
        {
            hasLetter = true;
        }
    }

    bool allUpper = isUpper && hasLetter;
    bool endsWithQuestion = trimmed.length > 0 && trimmed[$ - 1] == '?';

    // All uppercase and ends with ?
    if (allUpper && endsWithQuestion)
    {
        return "Calm down, I know what I'm doing!";
    }

    // All uppercase letters
    if (allUpper)
    {
        return "Whoa, chill out!";
    }

    // Ends with ?
    if (endsWithQuestion)
    {
        return "Sure.";
    }

    return "Whatever.";
}
