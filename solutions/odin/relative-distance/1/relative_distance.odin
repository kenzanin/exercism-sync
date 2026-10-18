package relative_distance

import "core:slice"

Name :: string
Children :: []Name
FamilyTree :: map[Name]Children

// Shortest path over an undirected graph. Two people are one step apart when
// one is a parent of the other, or when they are siblings (they share a
// parent) — see the README: "Isla and Tariq are siblings and have a
// separation of 1".
degree_of_separation :: proc(family: FamilyTree, from: string, to: string) -> int {
	if from == to do return 0
	if !_known(family, from) || !_known(family, to) do return -1

	visited := make(map[Name]bool)
	defer delete(visited)
	queue := make([dynamic]Name)
	defer delete(queue)

	visited[from] = true
	append(&queue, from)

	steps := 0
	for head := 0; head < len(queue); steps += 1 {
		level_end := len(queue)
		for ; head < level_end; head += 1 {
			if queue[head] == to do return steps
			_enqueue_neighbors(family, queue[head], &visited, &queue)
		}
	}
	return -1
}

// A person is a known node if they are a parent, or appear as someone's child.
_known :: proc(family: FamilyTree, person: Name) -> bool {
	if person in family do return true
	for _, kids in family {
		if slice.contains(kids, person) do return true
	}
	return false
}

// Parents, children, and siblings are each one connection away.
_enqueue_neighbors :: proc(family: FamilyTree, person: Name, visited: ^map[Name]bool, queue: ^[dynamic]Name) {
	for child in family[person] {
		if !visited[child] {
			visited[child] = true
			append(queue, child)
		}
	}

	for parent, siblings in family {
		if !slice.contains(siblings, person) do continue
		if !visited[parent] {
			visited[parent] = true
			append(queue, parent)
		}
		for sibling in siblings {
			if !visited[sibling] {
				visited[sibling] = true
				append(queue, sibling)
			}
		}
	}
}
