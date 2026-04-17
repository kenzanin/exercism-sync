module atbash_cipher;

private pure char toLowerChar(char c)
{
    return (c >= 'A' && c <= 'Z') ? cast(char)(c + ('a' - 'A')) : c;
}

import std.uni : isAlpha;

/// Encode the phrase using the Atbash cipher:
/// - Letters are mapped: a<->z, b<->y, ...
/// - Case-insensitive (output is lowercase)
/// - Non-alphanumeric characters are ignored
/// - Digits are preserved
/// - Output is grouped in blocks of 5 characters separated by spaces
pure string encode(immutable string phrase)
{
    char[] cleaned;
    foreach (c; phrase)
    {
        if (isAlpha(c))
            cleaned ~= toLowerChar(c);
        else if (c >= '0' && c <= '9')
            cleaned ~= c;
        else
        {
            // ignore punctuation/whitespace
        }
    }

    // Apply Atbash mapping
    char[] mapped;
    foreach (c; cleaned)
    {
        if (isAlpha(c))
        {
            // map 'a'..'z' to 'z'..'a'
            immutable char lc = toLowerChar(c);
            mapped ~= cast(char)('a' + ('z' - lc));
        }
        else // digit
            mapped ~= c;
    }

    // Group in blocks of 5
    string result;
    int count = 0;
    foreach (ch; mapped)
    {
        if (count == 5)
        {
            result ~= ' ';
            count = 0;
        }
        result ~= ch;
        ++count;
    }

    return result;
}

/// Decode the phrase encoded with Atbash:
/// - Remove spaces and punctuation
/// - Map letters back with the same Atbash mapping (symmetric)
/// - Preserve digits
/// - Return lowercase contiguous string (no grouping)
pure string decode(immutable string phrase)
{
    char[] cleaned;
    foreach (c; phrase)
    {
        if (isAlpha(c))
            cleaned ~= toLowerChar(c);
        else if (c >= '0' && c <= '9')
            cleaned ~= c;
        else
        {
            // ignore
        }
    }

    char[] result;
    foreach (c; cleaned)
    {
        if (isAlpha(c))
        {
            immutable char lc = toLowerChar(c);
            result ~= cast(char)('a' + ('z' - lc));
        }
        else
            result ~= c;
    }

    return result.idup;
}
