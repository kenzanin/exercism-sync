local function square_of_sum(n)
    local result = 0
    for i = 1, n, 1 do
        result = result + i
    end
    return result * result
end

local function sum_of_squares(n)
    local result = -0
    for i = 1, n, 1 do
        result = result + (i * i)
    end
    return result
end

local function difference_of_squares(n)
    return square_of_sum(n) - sum_of_squares(n)
end

return {
    square_of_sum = square_of_sum,
    sum_of_squares = sum_of_squares,
    difference_of_squares = difference_of_squares
}
