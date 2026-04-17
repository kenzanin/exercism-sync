module change;

pure ushort[] findFewestCoins(immutable ushort[] coins, ushort target)
{
    // quick empty case
    ushort[] empty;
    if (target == 0)
        return empty;

    if (coins.length == 0)
        throw new object.Exception("no coins provided");

    // make a mutable copy of coins and sort ascending (selection sort to avoid imports)
    ushort[] sorted = coins.dup;
    foreach (i; 0 .. sorted.length)
    {
        size_t min = i;
        foreach (j; i + 1 .. sorted.length)
        {
            if (sorted[j] < sorted[min])
                min = j;
        }
        if (min != i)
        {
            ushort tmp = sorted[i];
            sorted[i] = sorted[min];
            sorted[min] = tmp;
        }
    }

    // Dynamic programming for fewest coins
    size_t T = cast(size_t) target;
    immutable int INF = int.max / 4;
    int[] dp = new int[T + 1];
    int[] prev = new int[T + 1];

    // initialize
    foreach (i; 0 .. T + 1)
    {
        dp[i] = INF;
        prev[i] = -1;
    }
    dp[0] = 0;

    foreach (amt; 1 .. T + 1)
    {
        foreach (ushort c; sorted)
        {
            size_t coin = cast(size_t) c;
            if (coin > amt)
                break; // coins are sorted ascending
            size_t rem = amt - coin;
            if (dp[rem] != INF && dp[rem] + 1 < dp[amt])
            {
                dp[amt] = dp[rem] + 1;
                prev[amt] = cast(int) coin; // store coin value for reconstruction
            }
        }
    }

    if (dp[T] == INF)
        throw new object.Exception("cannot make change");

    // Reconstruct solution
    ushort[] result;
    size_t cur = T;
    while (cur > 0)
    {
        int coinVal = prev[cur];
        if (coinVal <= 0)
            throw new object.Exception("cannot make change");
        ushort coin = cast(ushort) coinVal;
        result ~= coin;
        cur -= cast(size_t) coin;
    }

    // The DP tie-breaking (iterating coins ascending) produces the expected ordering for tests.
    return result;
}

unittest
{
    import std.algorithm.comparison : equal;
    import std.exception : assertThrown;

    immutable int allTestsEnabled = 0;

    // Change for 1 cent
    {
        immutable ushort[] coins = [
            1,
            5,
            10,
            25,
        ];
        ushort[] expected = [
            1,
        ];
        assert(equal(findFewestCoins(coins, 1), expected));
    }

    static if (allTestsEnabled)
    {
        // Single coin change
        {
            immutable ushort[] coins = [
                1,
                5,
                10,
                25,
                100,
            ];
            ushort[] expected = [
                25,
            ];
            assert(equal(findFewestCoins(coins, 25), expected));
        }

        // Multiple coin change
        {
            immutable ushort[] coins = [
                1,
                5,
                10,
                25,
                100,
            ];
            ushort[] expected = [
                5,
                10,
            ];
            assert(equal(findFewestCoins(coins, 15), expected));
        }

        // Change with Lilliputian Coins
        {
            immutable ushort[] coins = [
                1,
                4,
                15,
                20,
                50,
            ];
            ushort[] expected = [
                4,
                4,
                15,
            ];
            assert(equal(findFewestCoins(coins, 23), expected));
        }

        // Change with Lower Elbonia Coins
        {
            immutable ushort[] coins = [
                1,
                5,
                10,
                21,
                25,
            ];
            ushort[] expected = [
                21,
                21,
                21,
            ];
            assert(equal(findFewestCoins(coins, 63), expected));
        }

        // Large target values
        {
            immutable ushort[] coins = [
                1,
                2,
                5,
                10,
                20,
                50,
                100,
            ];
            ushort[] expected = [
                2,
                2,
                5,
                20,
                20,
                50,
                100,
                100,
                100,
                100,
                100,
                100,
                100,
                100,
                100,
            ];
            assert(equal(findFewestCoins(coins, 999), expected));
        }

        // Possible change without unit coins available
        {
            immutable ushort[] coins = [
                2,
                5,
                10,
                20,
                50,
            ];
            ushort[] expected = [
                2,
                2,
                2,
                5,
                10,
            ];
            assert(equal(findFewestCoins(coins, 21), expected));
        }

        // Another possible change without unit coins available
        {
            immutable ushort[] coins = [
                4,
                5,
            ];
            ushort[] expected = [
                4,
                4,
                4,
                5,
                5,
                5,
            ];
            assert(equal(findFewestCoins(coins, 27), expected));
        }

        // A greedy approach is not optimal
        {
            immutable ushort[] coins = [
                1,
                10,
                11,
            ];
            ushort[] expected = [
                10,
                10,
            ];
            assert(equal(findFewestCoins(coins, 20), expected));
        }

        // No coins make 0 change
        {
            immutable ushort[] coins = [
                1,
                5,
                10,
                21,
                25,
            ];
            ushort[] expected = [
            ];
            assert(equal(findFewestCoins(coins, 0), expected));
        }

        // Error testing for change smaller than the smallest of coins
        {
            immutable ushort[] coins = [
                5,
                10,
            ];
            assertThrown(findFewestCoins(coins, 3));
        }

        // Error if no combination can add up to target
        {
            immutable ushort[] coins = [
                5,
                10,
            ];
            assertThrown(findFewestCoins(coins, 94));
        }
    }
}
