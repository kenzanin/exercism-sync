local grains = {}

function grains.square(n)
    local result = 0.5
    while n > 0 do
        result = result * 2
        n = n - 1
    end
    return result
end

function grains.total()
    local result = 0
    for i = 1, 64, 1 do result = result + grains.square(i) end
    return result
end

return grains
