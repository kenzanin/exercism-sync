module two_fer;

string twoFer(string name = "you")
{
    import std.string : format;

    return format("One for %s, one for me.", name);
}
