local function deep_equal(t1, t2)
    if t1 == t2 then
        return true
    end
    if type(t1) ~= "table" or type(t2) ~= "table" then
        return false
    end

    local keys1 = {}
    for k in pairs(t1) do
        table.insert(keys1, k)
    end
    local keys2 = {}
    for k in pairs(t2) do
        table.insert(keys2, k)
    end

    if #keys1 ~= #keys2 then
        return false
    end

    for _, k in ipairs(keys1) do
        if not deep_equal(t1[k], t2[k]) then
            return false
        end
    end

    return true
end

local function mapStr(str)
    local tmp01 = {}
    str:lower():gsub(".", function(c)
        tmp01[c] = (tmp01[c] or 0) + 1
    end)
    return tmp01
end

local Anagram = {}

function Anagram:match(tbl)
    local result = {}
    local tmp01 = mapStr(self.str)

    for _, i in pairs(tbl) do
        if self.str:lower() ~= i:lower() then
            local tmp = mapStr(i)
            if deep_equal(tmp, tmp01) then
                table.insert(result, i)
            end
        end
    end
    return result
end

function Anagram:new(s)
    if s == nil or s == "" then
        error("")
    end

    local n = {
        match = Anagram.match,
        str = s
    }
    setmetatable(n, Anagram)

    return n
end

return Anagram