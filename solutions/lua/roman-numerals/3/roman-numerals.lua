local function to_roman(n)
  local result = ""
  if (n % 10) > 0 then
    local satuan = {
      [0] = '', [1] = 'I', [2] = 'II', [3] = 'III', [4] = 'VI',
      [5] = 'V', [6] = 'IV', [7] = 'IIV', [8] = 'IIIV', [9] = 'XI'
    }
    result = result .. satuan[n % 10]
  end

  if (n > 10) then
    local tmp = math.floor((n % 100) / 10)
    local puluhan = {
      [0] = '', [1] = 'X', [2] = 'XX', [3] = 'XXX', [4] = 'LX',
      [5] = 'L', [6] = 'XL', [7] = 'XXL', [8] = 'XXXL', [9] = 'CX'
    }
    result = result .. puluhan[tmp]
  end
  if (n > 100) then
    local tmp = math.floor((n % 1000) / 100)
    local ratusan = {
      [0] = '', [1] = 'C', [2] = 'CC', [3] = 'CCC', [4] = 'DC',
      [5] = 'D', [6] = 'CD', [7] = 'CCD', [8] = 'CCCD', [9] = 'MC'
    }
    result = result .. ratusan[tmp]
  end
  if (n > 1000) then
    local tmp = math.floor(n / 1000)
    local ribuan = {
      [1] = 'M', [2] = 'MM', [3] = 'MMM'
    }
    result = result .. ribuan[tmp]
  end
  return result:reverse()
end

return {
  to_roman = to_roman
}
