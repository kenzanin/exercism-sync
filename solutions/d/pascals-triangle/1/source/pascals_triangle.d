module pascals_triangle;

pure int[][] rows(int count)
{
    // Return empty for non-positive counts
    if (count <= 0)
        return [];

    int[][] result;
    int[] prev;

    foreach (i; 1 .. count + 1)
    {
        int[] row = new int[i];
        row[0] = 1;
        row[$ - 1] = 1;
        if (i > 2)
        {
            foreach (j; 1 .. i - 1)
            {
                // prev has length i-1, so indices j-1 and j exist
                row[j] = prev[j - 1] + prev[j];
            }
        }
        result ~= row;
        prev = row;
    }

    return result;
}

unittest
{
    immutable int allTestsEnabled = 0;

    // Zero rows
    {
        int[][] expected = [
        ];
        assert(rows(0) == expected);
    }

    static if (allTestsEnabled)
    {
        // Single row
        {
            int[][] expected = [
                [1],
            ];
            assert(rows(1) == expected);
        }

        // Two rows
        {
            int[][] expected = [
                [1],
                [1, 1],
            ];
            assert(rows(2) == expected);
        }

        // Three rows
        {
            int[][] expected = [
                [1],
                [1, 1],
                [1, 2, 1],
            ];
            assert(rows(3) == expected);
        }

        // Four rows
        {
            int[][] expected = [
                [1],
                [1, 1],
                [1, 2, 1],
                [1, 3, 3, 1],
            ];
            assert(rows(4) == expected);
        }

        // Five rows
        {
            int[][] expected = [
                [1],
                [1, 1],
                [1, 2, 1],
                [1, 3, 3, 1],
                [1, 4, 6, 4, 1],
            ];
            assert(rows(5) == expected);
        }

        // Six rows
        {
            int[][] expected = [
                [1],
                [1, 1],
                [1, 2, 1],
                [1, 3, 3, 1],
                [1, 4, 6, 4, 1],
                [1, 5, 10, 10, 5, 1],
            ];
            assert(rows(6) == expected);
        }

        // Ten rows
        {
            int[][] expected = [
                [1],
                [1, 1],
                [1, 2, 1],
                [1, 3, 3, 1],
                [1, 4, 6, 4, 1],
                [1, 5, 10, 10, 5, 1],
                [1, 6, 15, 20, 15, 6, 1],
                [1, 7, 21, 35, 35, 21, 7, 1],
                [1, 8, 28, 56, 70, 56, 28, 8, 1],
                [1, 9, 36, 84, 126, 126, 84, 36, 9, 1],
            ];
            assert(rows(10) == expected);
        }
    }
}
