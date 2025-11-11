local all_your_base = {}
all_your_base.convert = function(from_digits, from_base)
  if from_base < 2 then
    error("invalid input base")
  end
  local result = 0
  local self = {}
  for i = 1, #from_digits, 1 do
    local tmp = from_digits[#from_digits - (i - 1)]
    if tmp < 0 then
      error("negative digits are not allowed")
    elseif tmp >= from_base then
      error("digit out of range")
    end
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
    if base < 2 then
      error("invalid output base")
    end
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
