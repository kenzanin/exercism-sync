local cmds = {
  A = {
    north = function(self)
      self.y = self.y + 1
    end,
    west = function(self)
      self.x = self.x - 1
    end,
    east = function(self)
      self.x = self.x + 1
    end,
    south = function(self)
      self.y = self.y - 1
    end
  },
  R = {
    north = function(self)
      self.heading = "east"
    end,
    west = function(self)
      self.heading = "north"
    end,
    south = function(self)
      self.heading = "west"
    end,
    east = function(self)
      self.heading = "south"
    end
  },
  L = {
    north = function(self)
      self.heading = "west"
    end,
    west = function(self)
      self.heading = "south"
    end,
    south = function(self)
      self.heading = "east"
    end,
    east = function(self)
      self.heading = "north"
    end
  }
}

local function move(self, cmd)
  for i in cmd:gmatch(".") do
    cmds[i][self.heading](self)
  end
end

return function(config)
  return {
    x = config.x,
    y = config.y,
    heading = config.heading,
    move = move
  }
end
