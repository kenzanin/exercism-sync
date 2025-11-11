local clock = {}

function clock.at(hour, minute)
    local n = {
        minute = 0,
        plus = clock.plus,
        minus = clock.minus,
        equals = clock.equals,
        __tostring = clock.__tostring
    }

    hour = (hour or 0)
    minute = (minute or 0)
    n.minute = (hour * 60 + minute) % (24 * 60)

    setmetatable(n, clock)
    return n
end

function clock:plus(n)
    self.minute = self.minute + n
    return self
end

function clock:minus(n)
    self.minute = self.minute - n
    return self
end

function clock:equals(clk)
    local result
    result = (self.minute == clk.minute)
    return result
end

function clock:__tostring()
    return string.format("%02d:%02d", math.floor(self.minute / 60) % 24,
                         self.minute % 60)
end

return clock
