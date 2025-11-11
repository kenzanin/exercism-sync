local function list(score)
  local result = {}
  local count = 1
  if score <= 0 then
    return result
  end
  local const alergen = {
    "eggs",
    "peanuts",
    "shellfish",
    "strawberries",
    "tomatoes",
    "chocolate",
    "pollen",
    "cats"
  }
  for i = 0, 7, 1 do
    if (score & 1 << i) ~= 0 then
      result[count] = alergen[i + 1]
      count = count + 1
    end
  end
  return result
end

local function allergic_to(score, which)
  local const listAlergen = list(score)
  for i = 1, #listAlergen, 1 do
    if listAlergen[i] == which then
      return true
    end
  end
  return false
end

return {
  list = list,
  allergic_to = allergic_to
}
