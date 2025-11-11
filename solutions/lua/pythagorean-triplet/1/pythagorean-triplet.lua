return function(sum)
    local results = {}
    local i = 0
    while i < (sum / 3) do
        local ii = i
        while ii < (sum / 2) do
            local iii = sum - i - ii
            if ((i * i) + (ii * ii)) == iii * iii then
                table.insert(results, {i, ii, iii})
            end
            ii = ii + 1
        end
        i = i + 1
    end
    return results
end
