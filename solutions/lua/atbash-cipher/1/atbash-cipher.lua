local function atoz(c)
    if string.byte(c) < string.byte('a') or string.byte(c) > string.byte('z') then
        return c
    end
    return string.char((string.byte('z') - c:byte()) + string.byte('a'))
end

return {
    encode = function(plaintext)
        local result = ""
        local count = 1
        for i in plaintext:gmatch("%w") do
            result = result .. atoz(i:lower())
            if count % 5 == 0 then result = result .. " " end
            count = count + 1
        end
        if result:sub(#result, #result) == ' ' then
            result = result:sub(1, #result - 1)
        end
        return result
    end
}
