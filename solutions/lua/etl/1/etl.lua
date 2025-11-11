return {
    transform = function(dataset)
        local data = {}
        for i, ii in pairs(dataset) do
            for _, iiii in pairs(ii) do data[iiii:lower()] = i end
        end
        return data
    end
}
