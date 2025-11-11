local function translate_codon(codon)
  local mapping <const> = {
    AUG = "Methionine",
    UUU = "Phenylalanine",
    UUC = "Phenylalanine",
    UUA = "Leucine",
    UUG = "Leucine",
    UCC = "Serine",
    UCA = "Serine",
    UCG = "Serine",
    UCU = "Serine",
    UAU = "Tyrosine",
    UAC = "Tyrosine",
    UGU = "Cysteine",
    UGC = "Cysteine",
    UGG = "Tryptophan",
    UAA = "STOP",
    UAG = "STOP",
    UGA = "STOP"
  }

  if (mapping[codon] == nil) then
    error()
  end
  return mapping[codon]
end

local function translate_rna_strand(rna_strand)
  local result = {}
  for i = 1, #rna_strand, 3 do
    local tmp = string.sub(rna_strand, i, i + 2)
    tmp = translate_codon(tmp)
    if tmp == "STOP" then
      return result
    end
    table.insert(result, tmp)
  end
  return result
end

return {
  codon = translate_codon,
  rna_strand = translate_rna_strand
}
