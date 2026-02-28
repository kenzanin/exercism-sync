local Hamming = {}

function Hamming.compute(a,b)
	local result=0

	if a:len() ~= b:len() then
	    error("strands must be of equal length")
	end

	for i=1,#a do
		if a:sub(i,i) ~= b:sub(i,i) then
			result=result+1
		end
	end

	return result
end
return Hamming

--Hamming.compute('CT','AG')
