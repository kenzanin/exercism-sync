local PhoneNumber = {}

PhoneNumber.number = ""
function PhoneNumber:new(number)
    setmetatable(PhoneNumber, {__tostring = self.__tostring})
    self.number = number:gsub("[()%- .]+", "")
    if #self.number >= 11 then
        if self.number:match("%d") == "1" then
            self.number = self.number:sub(2)
        else
            self.number = ("0"):rep(10)
        end
    elseif #self.number <= 9 then
        self.number = ("0"):rep(10)
    end
    return self
end

function PhoneNumber:areaCode() return self.number:sub(1, 3) end

function PhoneNumber:__tostring()
    return
        ("(" .. self.number:sub(1, 3) .. ") " .. self.number:sub(4, 6) .. "-" ..
            self.number:sub(7))
end

return PhoneNumber
