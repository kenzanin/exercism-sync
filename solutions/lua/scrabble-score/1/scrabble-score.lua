local function score(word)
    if word == nil then
        return 0
    end
    if #word == 0 then
        return 0
    end

    local mapping = {
        Q = 10, Z = 10,
        J = 8, X = 8,
        K = 5,
        F = 4, H = 4, V = 4, W = 4, Y = 4,
        B = 3, C = 3, M = 3, P = 3,
        D = 2, G = 2,
        A = 1, E = 1, I = 1, O = 1, U = 1, L = 1, N = 1, R = 1, S = 1, T = 1
    }
    word = word:upper()
    local result = 0
    for i in word:gmatch(".") do
        result = result + mapping[i]
    end
    return result
end

return { score = score }
