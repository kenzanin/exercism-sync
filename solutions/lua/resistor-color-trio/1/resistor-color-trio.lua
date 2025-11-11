return {
  decode = function(c1, c2, c3)
    local unit=0
    local value=0
    local res={}
    res['black']=0
    res['brown']=1
    res['red']=2
    res['orange']=3
    res['yellow']=4
    res['green']=5
    res['blue']=6
    res['violet']=7
    res['grey']=8
    res['white']=9

    value=res[c1]*10 + res[c2]

    if res[c3] == 0 then 
      unit="ohms"
    elseif res[c3] == 1 then 
      unit="ohms"
      value = value * 10
    elseif res[c3] == 2 then 
      unit="kiloohms"
      value = value / 10
    elseif res[c3] == 3 then 
      unit = "kiloohms"
    elseif res[c3] == 4 then
      unit = "kiloohms"
      value = value * 10
    end 
    return value,unit
  end
}

--print(decode('red','red','red'))
