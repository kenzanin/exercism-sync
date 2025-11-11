local function sortStr(str)
  local tmp01 = {}
  local result = ""
  str:lower():gsub(".", function(c)
    table.insert(tmp01, c)
  end)

  table.sort(tmp01)
  for _, i in pairs(tmp01) do
    result = result .. i
  end
  return result
end

local Anagram = {}

function Anagram:match(tbl)
  local result = {}
  for _, i in pairs(tbl) do
    local tmp = sortStr(i)
    if tmp == self.str then
      table.insert(result, i)
    end
  end
  return result
end

function Anagram:new(s)
  if s == nil or s == "" then
    error("")
  end
  local str = sortStr(s)
  local n = {
    match = Anagram.match,
    str = str
  }
  setmetatable(n, Anagram)
  return n
end

return Anagram
