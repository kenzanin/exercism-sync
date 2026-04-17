module affine_cipher;

import std.uni : isAlpha;
import std.exception : enforce;

/// Return gcd of two unsigned ints
pure uint gcd(uint a, uint b)
{
    while (b != 0)
    {
        uint t = a % b;
        a = b;
        b = t;
    }
    return a;
}

/// Extended Euclidean algorithm to find modular inverse of a modulo m.
/// Returns inverse in range [0, m-1] or throws if inverse does not exist.
pure int modInverse(int a, int m)
{
    int t = 0, newt = 1;
    int r = m, newr = a;
    while (newr != 0)
    {
        int q = r / newr;
        int tmp = newt;
        newt = t - q * newt;
        t = tmp;

        tmp = newr;
        newr = r - q * newr;
        r = tmp;
    }
    if (r > 1)
        throw new Exception("a is not invertible");
    if (t < 0)
        t += m;
    return t;
}

/* Removed unused helper: _charsToGroups was not used anywhere in this module. */

pure string encode(immutable string phrase, uint a, uint b)
{
    enum uint M = 26;
    // validate a coprime with 26
    if (gcd(a, M) != 1)
        throw new Exception("a and m must be coprime");

    // build normalized transformed string (letters substituted, digits preserved)
    char[] buffer;
    foreach (c; phrase)
    {
        immutable char lc = (c >= 'A' && c <= 'Z') ? cast(char)(c + ('a' - 'A')) : c;
        if (isAlpha(lc))
        {
            int x = cast(int)(lc - 'a');
            int enc = (cast(int)(a) * x + cast(int)(b)) % cast(int)(M);
            buffer ~= cast(char)(enc + 'a');
        }
        else if (c >= '0' && c <= '9')
        {
            buffer ~= c;
        }
        else
        {
            // ignore punctuation and spaces
        }
    }

    // group into blocks of 5
    string result;
    int count = 0;
    foreach (ch; buffer)
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

pure string decode(immutable string phrase, uint a, uint b)
{
    enum uint M = 26;
    if (gcd(a, M) != 1)
        throw new Exception("a and m must be coprime");

    int inv = modInverse(cast(int)(a), cast(int)(M));

    char[] buffer;
    foreach (c; phrase)
    {
        if (isAlpha(c))
        {
            immutable char lc = (c >= 'A' && c <= 'Z') ? cast(char)(c + ('a' - 'A')) : c;
            int y = cast(int)(lc - 'a');
            int dec = (inv * (y - cast(int)(b))) % cast(int)(M);
            if (dec < 0)
                dec += cast(int)(M);
            buffer ~= cast(char)(dec + 'a');
        }
        else if (c >= '0' && c <= '9')
        {
            buffer ~= c;
        }
        else
        {
            // ignore spaces and punctuation
        }
    }
    return buffer.idup;
}
