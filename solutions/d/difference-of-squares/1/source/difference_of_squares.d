module difference_of_squares;

struct Squares
{
    int sumOfSquares;
    int squareOfSum;
    int difference;
}

pure Squares squares(int n)
{
    // Validate input: n should be non-negative
    if (n < 0)
        throw new object.Exception("n must be non-negative");

    // sum of first n natural numbers: n * (n + 1) / 2
    long s = cast(long) n * (n + 1) / 2;
    // square of the sum
    long sqOfSumLong = s * s;

    // sum of squares formula: n * (n + 1) * (2n + 1) / 6
    long sumSqLong = cast(long) n * (n + 1) * (2 * n + 1) / 6;

    // Fit results into int; test values are within int range for the exercise
    int sumOfSquares = cast(int) sumSqLong;
    int squareOfSum = cast(int) sqOfSumLong;
    int difference = cast(int)(sqOfSumLong - sumSqLong);

    return Squares(sumOfSquares, squareOfSum, difference);
}

unittest
{
    immutable int allTestsEnabled = 0;

    // Square of sum 1
    assert(squares(1).squareOfSum == 1);

    static if (allTestsEnabled)
    {
        // Square of sum 5
        assert(squares(5).squareOfSum == 225);

        // Square of sum 100
        assert(squares(100).squareOfSum == 25_502_500);

        // Sum of squares 1
        assert(squares(1).sumOfSquares == 1);

        // Sum of squares 5
        assert(squares(5).sumOfSquares == 55);

        // Sum of squares 100
        assert(squares(100).sumOfSquares == 338_350);

        // Difference of squares 100
        assert(squares(100).difference == 25_164_150);
    }

}
