local function hand(number)
    local result = {}
    if number == 0 or number == nil then return result end
    local mapping <const> = {
        [1] = "wink",
        [2] = "double blink",
        [4] = "close your eyes",
        [8] = "jump",
    }
    for _, i in pairs({ 1, 2, 4, 8 }) do
        if i > number then
            break
        end
        table.insert(result, mapping[number & i])
    end
    if (number & 16) == 16 then
        local rev = {}
        for i = #result, 1, -1 do
            table.insert(rev,result[i])
        end
        result = rev
    end
    return result
end

return hand
