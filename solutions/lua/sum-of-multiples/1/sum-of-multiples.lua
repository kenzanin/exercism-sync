local function sum(numbers)
  local result_t = {}
  local result = 0
  return {
    to = function(limit)
      for _, i in pairs(numbers) do
        local ii = i
        while ii < limit do
          table.insert(result_t, ii)
          ii = ii + i
        end
      end
      table.sort(result_t);
      for i, ii in pairs(result_t) do
        local _, yy = next(result_t, i)
        if ii == yy then
          ii = 0
        end
        result = result + ii
      end
      return result
    end
  }
end

return sum
