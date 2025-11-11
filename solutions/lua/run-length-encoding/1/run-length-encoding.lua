return {
  encode = function(s)
    if #s == 1 then
      error("")
    end
    local result = ""
    local i = 1
    while i <= #s do
      local tmp = s:sub(i, i)
      local count = 0
      while tmp == s:sub(i, i) do
        count = count + 1
        i = i + 1
      end
      if count == 1 then
        result = result .. tmp
      else
        result = result .. count .. tmp
      end
    end
    return result
  end,

  decode = function(s)
    local result = ""
    local num = ""
    local char = ""
    local i = 1
    while i <= #s do
      local char = s:sub(i, i)
      if tonumber(char) ~= nil then
        num = num .. char
        goto continue
      end
      num = (num or "")
      if num ~= "" then
        result = result .. string.rep(char, tonumber(num))
        num = ""
      else
        result = result .. char
      end
      ::continue::
      i = i + 1
    end
    return result
  end
}
