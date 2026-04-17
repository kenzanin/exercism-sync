module book_store;

pure int total(immutable int[] basket)
{
    // Potter kata pricing:
    // base price per book: 800
    // discounts for sets of distinct books:
    // 2 -> 5%, 3 -> 10%, 4 -> 20%, 5 -> 25%
    if (basket.length == 0)
        return 0;

    // Count occurrences of each title (IDs expected in 1..5)
    int[6] counts;
    foreach (b; basket)
    {
        if (b >= 1 && b <= 5)
            ++counts[b];
    }

    // Build groups greedily: each group takes one copy of as many distinct titles as available
    int[6] groupsBySize; // index = size -> number of groups of that size
    while (true)
    {
        int distinct = 0;
        foreach (i; 1 .. 6)
        {
            if (counts[i] > 0)
            {
                --counts[i];
                ++distinct;
            }
        }
        if (distinct == 0)
            break;
        ++groupsBySize[distinct];
    }

    // Optimization:
    // It is cheaper to replace one 5-group + one 3-group with two 4-groups.
    // Adjust groups accordingly while possible.
    while (groupsBySize[5] > 0 && groupsBySize[3] > 0)
    {
        --groupsBySize[5];
        --groupsBySize[3];
        groupsBySize[4] += 2;
    }

    // Discounts
    double[6] discount;
    discount[0] = 0.0;
    discount[1] = 0.0;
    discount[2] = 0.05;
    discount[3] = 0.10;
    discount[4] = 0.20;
    discount[5] = 0.25;

    double totalPrice = 0.0;
    immutable double unit = 800.0;
    foreach (size; 1 .. 6)
    {
        if (groupsBySize[size] > 0)
        {
            double pricePerGroup = size * unit * (1.0 - discount[size]);
            totalPrice += pricePerGroup * groupsBySize[size];
        }
    }

    return cast(int) totalPrice;
}

unittest
{
    immutable int allTestsEnabled = 0;

    // Only a single book
    {
        immutable int[] basket = [1];
        assert(total(basket) == 800);
    }

    static if (allTestsEnabled)
    {
        // Two of the same book
        {
            immutable int[] basket = [2, 2];
            assert(total(basket) == 1600);
        }

        // Empty basket
        {
            immutable int[] basket = [];
            assert(total(basket) == 0);
        }

        // Two different books
        {
            immutable int[] basket = [1, 2];
            assert(total(basket) == 1520);
        }

        // Three different books
        {
            immutable int[] basket = [1, 2, 3];
            assert(total(basket) == 2160);
        }

        // Four different books
        {
            immutable int[] basket = [1, 2, 3, 4];
            assert(total(basket) == 2560);
        }

        // Five different books
        {
            immutable int[] basket = [1, 2, 3, 4, 5];
            assert(total(basket) == 3000);
        }

        // Two groups of four is cheaper than group of five plus group of three
        {
            immutable int[] basket = [1, 1, 2, 2, 3, 3, 4, 5];
            assert(total(basket) == 5120);
        }

        // Two groups of four is cheaper than groups of five and three
        {
            immutable int[] basket = [1, 1, 2, 3, 4, 4, 5, 5];
            assert(total(basket) == 5120);
        }

        // Group of four plus group of two is cheaper than two groups of three
        {
            immutable int[] basket = [1, 1, 2, 2, 3, 4];
            assert(total(basket) == 4080);
        }

        // Two each of first four books and one copy each of rest
        {
            immutable int[] basket = [1, 1, 2, 2, 3, 3, 4, 4, 5];
            assert(total(basket) == 5560);
        }

        // Two copies of each book
        {
            immutable int[] basket = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5];
            assert(total(basket) == 6000);
        }

        // Three copies of first book and two each of remaining
        {
            immutable int[] basket = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 1];
            assert(total(basket) == 6800);
        }

        // Three each of first two books and two each of remaining books
        {
            immutable int[] basket = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 2];
            assert(total(basket) == 7520);
        }

        // Four groups of four are cheaper than two groups each of five and three
        {
            immutable int[] basket = [
                1, 1, 2, 2, 3, 3, 4, 5, 1, 1, 2, 2, 3, 3, 4, 5
            ];
            assert(total(basket) == 10240);
        }

        // Check that groups of four are created properly even when there are
        // more groups of three than groups of five
        {
            immutable int[] basket = [
                1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
                3, 3, 3, 3, 3, 3, 4, 4, 5, 5
            ];
            assert(total(basket) == 14560);
        }

        // One group of one and four is cheaper than one group of two and three
        {
            immutable int[] basket = [1, 1, 2, 3, 4];
            assert(total(basket) == 3360);
        }

        // One group of one and two plus three groups of four is cheaper than
        // one group of each size
        {
            immutable int[] basket = [
                1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5
            ];
            assert(total(basket) == 10000);
        }
    }
}
