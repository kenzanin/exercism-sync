return {
  valid = function(s)
    if #s < 2 or #s == nil or s:find("%a+") ~= nil then
      return false
    end
    local tmp01 = s:gsub("%W", "")
    tmp01 = string.reverse(tmp01)
    local tmp02 = {}
    tmp01:gsub(".", function(c)
      table.insert(tmp02, c)
    end)
    local result = 0
    for i, ii in pairs(tmp02) do
      if (i & 1) == 0 then
        ii = ii * 2
        if ii > 9 then
          ii = ii - 9
        end
      end
      result = result + ii
    end
    return (result % 10) == 0
  end
}
