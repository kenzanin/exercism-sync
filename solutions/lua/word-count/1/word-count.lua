local function word_count(s)
    local result = {}
    s = " " .. s:lower() .. " "
    s = s:gsub("[$!]", " "):gsub("%s'", " "):gsub("'%s", " ")
    for w in s:gmatch("[a-z0-9']+") do result[w] = (result[w] or 0) + 1 end
    return result
end

return {word_count = word_count}
