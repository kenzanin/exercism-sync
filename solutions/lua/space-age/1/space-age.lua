local SpaceAge = {}

SpaceAge.seconds = 0
function SpaceAge:new(number, n)
    n = (n or {})
    setmetatable(n, self)
    self.__index = self
    self.seconds = number
    return n
end

function SpaceAge.on_earth()
    local result = math.ceil((SpaceAge.seconds / 315576)) / 100
    return result
end
function SpaceAge.on_mercury()
    local result = math.floor(SpaceAge.on_earth() / 0.002408467) / 100
    return result
end
function SpaceAge.on_mars()
    local result = math.floor(SpaceAge.on_earth() / 0.018808158) / 100
    return result
end
function SpaceAge.on_jupiter()
    local result = math.ceil(SpaceAge.on_earth() / 0.11862615) / 100
    return result
end

function SpaceAge.on_saturn()
    local result = math.floor(SpaceAge.on_earth() / 0.29447498) / 100
    return result
end
function SpaceAge.on_uranus()
    local result = math.ceil(SpaceAge.on_earth() / 0.84016846) / 100
    return result
end
function SpaceAge.on_neptune()
    local result = math.floor(SpaceAge.on_earth() / 1.6479132) / 100
    return result
end

return SpaceAge
