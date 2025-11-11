local leap_year = function(number)
    if number % 4 == 0 then
        if (number % 100 == 0) and (number % 400 ~= 0) then return false end
        return true
    end
    return false
end

return leap_year
