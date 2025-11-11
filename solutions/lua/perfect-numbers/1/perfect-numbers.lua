local function aliquot_sum(n)
    local result = 0
    for i = 1, n - 1, 1 do if n % i == 0 then result = result + i end end
    return result
end

local function classify(n)
    if aliquot_sum(n) < n then
        return 'deficient'
    elseif aliquot_sum(n) > n then
        return 'abundant'
    else
        return 'perfect'
    end
end

return {aliquot_sum = aliquot_sum, classify = classify}
