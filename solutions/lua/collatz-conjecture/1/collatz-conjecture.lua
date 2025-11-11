local function colatz(number)
    if number <= 0 then
        error("Only positive numbers are allowed")
    end
    local step = 0
    while number ~= 1 do
        if (number & 1) == 0 then
            number = number / 2
        else
            number = (number * 3) + 1
        end
        step = step + 1
    end
    return step
end

return colatz
