local bob = {}

local function trim(s)
    return s:match("^%s*(.-)%s*$")
end

local function is_all_uppercase(say)
    return say:match("%a") and say == string.upper(say)
end

function bob.hey(say)
    local s = trim(say)
    local is_question = string.sub(s, -1) == "?"
    local is_shouting = s:match("%a") and s == string.upper(s)

    if #s == 0 then
        return "Fine. Be that way!"
    elseif is_shouting and is_question then
        return "Calm down, I know what I'm doing!"
    elseif is_shouting then
        return "Whoa, chill out!"
    elseif is_question then
        return "Sure."
    else
        return "Whatever."
    end
end

return bob
