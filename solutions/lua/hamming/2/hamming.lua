local Hamming = {}

function Hamming.compute(a,b)
	local result=0

	if string.len(a) ~= string.len(b) then
		return -1
	end

	if a == b then
		return 0
	end

  local c1={}
  local c2={}
  
  for i=1, #a do 
    c1[i]=string.sub(a,i,i)
  end
  
  for i=1,#b do 
    c2[i]=string.sub(b,i,i)
  end
  
  for i=1,#c1 do
    if c1[i] ~= c2[i] then
      result=result+1
    end
  end
  
	return result
end
return Hamming

--Hamming.compute('CT','AG')


