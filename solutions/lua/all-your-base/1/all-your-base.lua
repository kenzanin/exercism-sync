local all_your_base = {}
all_your_base.convert = function(from_digits, from_base)
  local result = 0
  local self = {}
  for i = 1, #from_digits, 1 do
    local tmp = from_digits[#from_digits - (i - 1)]
    result = result + (tmp * math.pow(from_base, (i - 1)))
  end
  local function reverse(arr)
    for i = 1, #arr / 2, 1 do
      local tmp = arr[i]
      arr[i] = arr[#arr - (i - 1)]
      arr[#arr - (i - 1)] = tmp
    end
    return arr
  end
  function self.to(base)
    local tmp = {}
    tmp[1] = 0
    local ii = 1
    while (result > 0) do
      tmp[ii] = math.floor(result % base)
      result = math.floor(result / base)
      ii = ii + 1
    end
    return reverse(tmp)
  end
  return self
end

return all_your_base
