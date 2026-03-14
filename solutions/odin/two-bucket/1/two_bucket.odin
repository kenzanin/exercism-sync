package two_bucket

import "core:fmt"

Result :: struct {
	moves:        int,
	goal_bucket:  string,
	other_bucket: int,
}

State :: struct {
	b1:    int,
	b2:    int,
	moves: int,
}

// Helper: Check if a state is forbidden
is_forbidden_state :: proc(
	b1: int,
	b2: int,
	start_bucket: string,
	capacity1: int,
	capacity2: int,
) -> bool {
	if start_bucket == "one" {
		return b1 == 0 && b2 == capacity2
	} else {
		return b2 == 0 && b1 == capacity1
	}
}

// Helper: Greatest Common Divisor using Euclid's algorithm
gcd :: proc(a: int, b: int) -> int {
	x := a
	y := b
	for y != 0 {
		temp := y
		y = x % y
		x = temp
	}
	return x
}

// Helper: Find minimum of two integers
min :: proc(a: int, b: int) -> int {
	if a < b {
		return a
	}
	return b
}

measure :: proc(
	bucket_one: int,
	bucket_two: int,
	goal: int,
	start_bucket: string,
) -> (
	Result,
	bool,
) {
	// Validate: Goal cannot be larger than both buckets
	if goal > bucket_one && goal > bucket_two {
		return Result{}, false
	}

	// Validate: Goal must be divisible by GCD of bucket sizes
	if goal % gcd(bucket_one, bucket_two) != 0 {
		return Result{}, false
	}

	// BFS state tracking
	visited := make(map[string]bool)
	defer delete(visited)

	queue := [dynamic]State{}
	defer delete(queue)

	// Initial state: fill the starting bucket
	if start_bucket == "one" {
		append(&queue, State{bucket_one, 0, 1})
	} else {
		append(&queue, State{0, bucket_two, 1})
	}

	// BFS loop
	for len(queue) > 0 {
		state := queue[0]
		ordered_remove(&queue, 0)

		// Check if we reached the goal
		if state.b1 == goal {
			return Result{state.moves, "one", state.b2}, true
		}
		if state.b2 == goal {
			return Result{state.moves, "two", state.b1}, true
		}

		// Skip if already visited
		state_key := fmt.tprintf("%d,%d", state.b1, state.b2)
		if state_key in visited {
			continue
		}
		visited[state_key] = true

		// Try all 6 possible actions

		// Action 1: Fill bucket 1
		if state.b1 != bucket_one {
			new_b1 := bucket_one
			new_b2 := state.b2
			if !is_forbidden_state(new_b1, new_b2, start_bucket, bucket_one, bucket_two) {
				append(&queue, State{new_b1, new_b2, state.moves + 1})
			}
		}

		// Action 2: Fill bucket 2
		if state.b2 != bucket_two {
			new_b1 := state.b1
			new_b2 := bucket_two
			if !is_forbidden_state(new_b1, new_b2, start_bucket, bucket_one, bucket_two) {
				append(&queue, State{new_b1, new_b2, state.moves + 1})
			}
		}

		// Action 3: Empty bucket 1
		if state.b1 != 0 {
			new_b1 := 0
			new_b2 := state.b2
			if !is_forbidden_state(new_b1, new_b2, start_bucket, bucket_one, bucket_two) {
				append(&queue, State{new_b1, new_b2, state.moves + 1})
			}
		}

		// Action 4: Empty bucket 2
		if state.b2 != 0 {
			new_b1 := state.b1
			new_b2 := 0
			if !is_forbidden_state(new_b1, new_b2, start_bucket, bucket_one, bucket_two) {
				append(&queue, State{new_b1, new_b2, state.moves + 1})
			}
		}

		// Action 5: Pour from bucket 1 to bucket 2
		if state.b1 != 0 && state.b2 != bucket_two {
			amount := min(state.b1, bucket_two - state.b2)
			new_b1 := state.b1 - amount
			new_b2 := state.b2 + amount
			if !is_forbidden_state(new_b1, new_b2, start_bucket, bucket_one, bucket_two) {
				append(&queue, State{new_b1, new_b2, state.moves + 1})
			}
		}

		// Action 6: Pour from bucket 2 to bucket 1
		if state.b2 != 0 && state.b1 != bucket_one {
			amount := min(state.b2, bucket_one - state.b1)
			new_b1 := state.b1 + amount
			new_b2 := state.b2 - amount
			if !is_forbidden_state(new_b1, new_b2, start_bucket, bucket_one, bucket_two) {
				append(&queue, State{new_b1, new_b2, state.moves + 1})
			}
		}
	}

	return Result{}, false
}
