local function rna(param)
    local result = ""
    local maping = {
        G = 'C', C = 'G', U = 'A', A = 'U', T = 'A'
    }
    for i in param:gmatch('.') do
        result = result .. maping[i]
    end
    return result
end

return rna
