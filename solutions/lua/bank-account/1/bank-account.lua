local account = {
    bal = 0,
    new = function(self, n)
        n = (n or {})
        setmetatable(n, self)
        self.__index = self
        self.bal = 0
        return n
    end,
    balance = function(self) return self.bal end,
    deposit = function(self, number)
        if number <= 1 or self.bal == -1 then error("") end
        self.bal = self.bal + number
    end,
    withdraw = function(self, number)
        if number <= 0 or self.bal < number then error("") end
        self.bal = self.bal - number
    end,
    close = function(self) self.bal = -1 end
}
return account
