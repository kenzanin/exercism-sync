local function getSignature(str)
	local counts = {}
	for c in str:lower():gmatch(".") do
		counts[c] = (counts[c] or 0) + 1
	end
	return counts
end

local function tablesEqual(t1, t2)
	for k, v in pairs(t1) do
		if t2[k] ~= v then return false end
	end
	for k, v in pairs(t2) do
		if t1[k] ~= v then return false end
	end
	return true
end

local Anagram = {}

function Anagram:match(tbl)
	local result = {}
	for _, i in pairs(tbl) do
		if string.lower(i) ~= self.str then
			if tablesEqual(self.sig, getSignature(i)) then
				table.insert(result, i)
			end
		end
	end
	return result
end

function Anagram:new(s)
	if s == nil or s == "" then
		error("")
	end
	local n = {
		match = Anagram.match,
		str = string.lower(s),
		sig = getSignature(s),
	}
	setmetatable(n, Anagram)
	return n
end

return Anagram
