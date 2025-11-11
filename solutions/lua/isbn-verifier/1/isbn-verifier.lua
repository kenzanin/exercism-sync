return {
  valid = function(isbn)
    local tmp = string.gsub(isbn, "%W+", "")
    if #tmp ~= 10 then
      return false
    end

    local tmp02 = {}
    tmp:gsub(".", function(c)
      table.insert(tmp02, c)
    end)

    local test = tmp02[10]:find("[0-9X]+")
    if test == nil then
      return false
    end
    if tmp02[10] == "X" then
      tmp02[10] = ":"
    end

    local ii = 1
    local check = 0
    for i = 10, 1, -1 do
      check = check + ((tmp02[ii]:byte() - ("0"):byte()) * i)
      ii = ii + 1
    end

    local result = check % 11
    if result == 0 then
      return true
    end
    return false
  end
}
