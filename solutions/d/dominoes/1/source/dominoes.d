module dominoes;

struct Stone {
    int left;
    int right;
}

pure bool canChain(immutable Stone[] dominoes)
{
    if (dominoes.length == 0)
        return true;

    import std.algorithm : canFind, count;
    import std.array : array;
    import std.container : DList;
    import std.container : redBlackTree;
    import std.range : array;

    int[int] counts;
    foreach (d; dominoes)
    {
        counts[d.left] = counts.get(d.left, 0) + 1;
        counts[d.right] = counts.get(d.right, 0) + 1;
    }

    int oddCount = 0;
    foreach (k, v; counts)
    {
        if (v % 2 == 1)
            oddCount++;
    }

    if (!(oddCount == 0 || oddCount == 2))
        return false;

    bool[int] seen;
    int componentSize = 0;
    DList!int queue = DList!int();
    
    queue.insertBack(dominoes[0].left);
    if (dominoes[0].left != dominoes[0].right)
        queue.insertBack(dominoes[0].right);
    
    seen[dominoes[0].left] = true;
    seen[dominoes[0].right] = true;
    componentSize = 1;
    
    int[] allEnds;
    foreach (d; dominoes)
    {
        allEnds ~= d.left;
        allEnds ~= d.right;
    }
    
    while (!queue.empty)
    {
        int current = queue.front;
        queue.removeFront();
        
        foreach (d; dominoes)
        {
            if (!seen.get(d.left, false))
            {
                if (d.left == current || d.right == current)
                {
                    seen[d.left] = true;
                    seen[d.right] = true;
                    queue.insertBack(d.left);
                    if (d.left != d.right)
                        queue.insertBack(d.right);
                    componentSize++;
                }
            }
        }
    }

    bool[int] uniqueEnds;
    foreach (e; allEnds)
        uniqueEnds[e] = true;
    
    return componentSize == uniqueEnds.length;
}

unittest
{
    immutable int allTestsEnabled = 0;

    // Empty input = empty output
    {
        immutable Stone[] dominoes;
        assert(canChain(dominoes));
    }

    static if (allTestsEnabled)
    {
        // Additional tests...
    }
}