local matrix = {}

matrix.table = {}
function matrix.new(s)
    local n = {}
    setmetatable(n, matrix)
    matrix.__index = matrix

    local index = 1
    for i in s:gmatch("[^\n]+") do
        local tmp = {}
        for ii in i:gmatch("%d+") do table.insert(tmp, tonumber(ii)) end
        matrix.table[index] = tmp
        index = index + 1
    end
    return n
end

function matrix.row(n) return matrix.table[n] end

function matrix.column(n)
    local result = {}
    for i = 1, #matrix.table, 1 do table.insert(result, matrix.table[i][n]) end
    return result
end

return matrix.new

--[[ local result = {}
 ]]
