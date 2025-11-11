local function to_decimal(input)
    local result = 0;
    for i = 0, #input - 1 do
        tmp = input:byte(#input - i) - 48
        if tmp < 0 or tmp > 9 then
          return 0
        end
        result = result + (tmp * math.pow(2, i))
    end
    return result
end

return {
    to_decimal = to_decimal
}
