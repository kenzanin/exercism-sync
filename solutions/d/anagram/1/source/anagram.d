module anagram;

import std.string : toLower;
import std.uni : isAlpha;
import std.conv : to;

pure string[] findAnagrams(immutable string subject, immutable string[] candidates)
{
    // Helper to produce a canonical frequency-count representation of a word
    auto key = (immutable string s) {
        int[26] counts;
        foreach (c; s.toLower())
        {
            if (isAlpha(c))
            {
                char lc = c;
                if (lc >= 'a' && lc <= 'z')
                    counts[lc - 'a']++;
            }
        }
        string res;
        foreach (i; 0 .. counts.length)
        {
            res ~= to!string(counts[i]);
            res ~= '|';
        }
        return res;
    };

    immutable string subjectKey = key(subject);
    string[] matches;

    foreach (candidate; candidates)
    {
        // identical words are not anagrams
        if (candidate.toLower() == subject.toLower())
            continue;
        if (key(candidate) == subjectKey)
            matches ~= candidate;
    }

    return matches;
}
