local function calc(seconds, planet_ratio)
    return math.floor(((seconds / 31557600.0) / planet_ratio) * 100 + 0.5) / 100
end

local SpaceAge = {}

SpaceAge.seconds = 0
function SpaceAge:new(number)
    local n = {}
    setmetatable(n, SpaceAge)
    self.__index = self
    SpaceAge.seconds = number
    return n
end

function SpaceAge.on_earth() return calc(SpaceAge.seconds, 1.0) end
function SpaceAge.on_mercury() return calc(SpaceAge.seconds, 0.2408467) end
function SpaceAge.on_mars() return calc(SpaceAge.seconds, 1.8808158) end
function SpaceAge.on_jupiter() return calc(SpaceAge.seconds, 11.862615) end
function SpaceAge.on_saturn() return calc(SpaceAge.seconds, 29.447498) end
function SpaceAge.on_uranus() return calc(SpaceAge.seconds, 84.016846) end
function SpaceAge.on_neptune() return calc(SpaceAge.seconds, 164.79132) end
function SpaceAge.on_venus() return calc(SpaceAge.seconds, 0.61519726) end

return SpaceAge
