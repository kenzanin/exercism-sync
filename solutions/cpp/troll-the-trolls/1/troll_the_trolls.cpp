namespace hellmath
{
    // TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
    // account types: `troll`, `guest`, `user`, and `mod`.
    enum AccountStatus
    {
        troll,
        guest,
        user,
        mod,
    };
    // TODO: Task 1 - Define an `Action` enumeration to represent the three
    // permission types: `read`, `write`, and `remove`.
    enum Action
    {
        read,
        write,
        remove,
    };
    // TODO: Task 2 - Implement the `display_post` function, that gets two arguments
    // of `AccountStatus` and returns a `bool`. The first argument is the status of
    // the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus in1, AccountStatus in2)
    {
        return in1 == AccountStatus::troll xor in2 == AccountStatus::troll ? false : true;
    }
    // TODO: Task 3 - Implement the `permission_check` function, that takes an
    // `Action` as a first argument and an `AccountStatus` to check against. It
    // should return a `bool`.
    bool permission_check(Action in1, AccountStatus in2)
    {
        switch (in2)
        {
        case user:
        case troll:
        {
            return in1 == read or in1 == write ? true : false;
        }
        case guest:
        {
            return in1 == read ? true : false;
        }
        case mod:
        {
            return true;
        }
        }
        return false;
    }
    // TODO: Task 4 - Implement the `valid_player_combination` function that
    // checks if two players can join the same game. The function has two parameters
    // of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus in1, AccountStatus in2)
    {
        switch (in1)
        {
        case guest:
            return false;
        case troll:
            return in2 == troll ? true : false;
        case mod:
        case user:
            return in2 == user or in2 == mod ? true : false;
        }
        return false;
    }
    // TODO: Task 5 - Implement the `has_priority` function that takes two
    // `AccountStatus` arguments and returns `true`, if and only if the first
    // account has a strictly higher priority than the second.
    bool has_priority(AccountStatus in1, AccountStatus in2)
    {
        switch (in1)
        {
        case troll:
            return false;
        case guest:
            return in2 == troll ? true : false;
        case user:
            return in2 == troll or in2 == guest ? true : false;
        case mod:
            return in2 == mod ? false : true;
        }

        return false;
    }
} // namespace hellmath