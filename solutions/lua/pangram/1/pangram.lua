return function(s)
    if s == '' or s == nil then return false end
    local atoz = "abcdefghijklmnopqrstuvwxyz"
    local tmp = s:gsub("%s+", ""):lower()
    for i in atoz:gmatch(".") do if tmp:find(i) == nil then return false end end
    return true
end