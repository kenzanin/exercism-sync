package robot_simulator

Heading :: enum {
	North,
	East,
	South,
	West,
}

Position :: struct {
	x: int,
	y: int,
}

Robot :: struct {
	pos: Position,
	hd:  Heading,
}

create_robot :: proc(x, y: int, dir: Heading) -> Robot {
	return {pos = {x, y}, hd = dir}
}

follow_commands :: proc(r: ^Robot, cmds: string) {
	valid_heading := proc(h: int) -> Heading {
		tmp01 := h
		if tmp01 > int(Heading.West) do tmp01 = int(Heading.North)
		if tmp01 < int(Heading.North) do tmp01 = int(Heading.West)
		return Heading(tmp01)
	}

	for c in cmds {
		switch c {
		case 'R':
			r.hd = valid_heading(int(r.hd) + 1)
		case 'L':
			r.hd = valid_heading(int(r.hd) - 1)
		case 'A':
			switch r.hd {
			case .North:
				r.pos.y += 1
			case .South:
				r.pos.y -= 1
			case .East:
				r.pos.x += 1
			case .West:
				r.pos.x -= 1
			}
		}
	}
}
