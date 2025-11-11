return function(s)
  local tmp = string.lower(s)
  tmp = tmp:gsub("-", "")
  tmp = tmp:gsub(" ", "")
  for i = 1, #tmp - 1, 1 do
    for ii = i + 1, #tmp, 1 do
      if tmp:byte(i) == tmp:byte(ii) then
        return false
      end
    end
  end
  return true
end
