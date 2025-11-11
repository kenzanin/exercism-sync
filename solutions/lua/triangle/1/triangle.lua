local function same(a, b, c)
    local result = 0
    if a == b then result = 1 end
    if b == c then result = result + 2 end
    if c == a then result = result + 4 end
    return result
end

local triangle = {}

function triangle.kind(a, b, c)
    if a <= 0 or b <= 0 or c <= 0 then error("Input Error") end
    if ((math.max(a, b, c) * 2) > (a + b + c)) then error("Input Error") end
    local mapping = {
        [7] = "equilateral",
        [1] = "isosceles",
        [2] = "isosceles",
        [4] = "isosceles",
        [0] = "scalene"
    }
    return mapping[same(a, b, c)]
end

return triangle
