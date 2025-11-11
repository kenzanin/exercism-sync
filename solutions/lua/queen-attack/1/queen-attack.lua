return function(pos)
    if pos.row < 0 or pos.row > 7 or pos.column < 0 or pos.column > 7 then
        error("")
    end
    return {
        pos = pos,
        can_attack = function(other)
            return (pos.column == other.pos.column) or
                       (pos.row == other.pos.row) or (pos.column + pos.row) ==
                       (other.pos.column + other.pos.row) or
                       (math.abs(pos.column - pos.row) ==
                        math.abs(other.pos.column - other.pos.row))
        end
    }
end
