local function validate(nuc, mesg)
  local valid = "ATCG"
  if valid:find(nuc) == nil then
    error(mesg)
  end
end

local DNA = {}

function DNA:new(nuc)
  self.nucleotideCounts = {
    A = 0,
    T = 0,
    C = 0,
    G = 0
  }
  if #nuc == 0 then
    return self
  end
  for i = 1, #nuc, 1 do
    validate(string.char(nuc:byte(i)), "Invalid Sequence")
    self.nucleotideCounts[string.char(nuc:byte(i))] = self.nucleotideCounts[string.char(nuc:byte(i))] + 1
  end
  return self
end

function DNA:count(nuc)
  validate(nuc, "Invalid Nucleotide")
  return self.nucleotideCounts[nuc]
end

return DNA
