package allergies

Allergen :: enum {
	Eggs,
	Peanuts,
	Shellfish,
	Strawberries,
	Tomatoes,
	Chocolate,
	Pollen,
	Cats,
}

Score := []int{1, 2, 4, 8, 16, 32, 64, 128}

allergic_to :: proc(score: int, allergen: Allergen) -> bool {
	return Score[int(allergen)] & score != 0
}

	list :: proc(score: int) -> []Allergen {
	result := make([dynamic]Allergen)
	if score & 1 > 0 do append(&result, Allergen.Eggs)
	if score & 2 > 0 do append(&result, Allergen.Peanuts)
	if score & 4 > 0 do append(&result, Allergen.Shellfish)
	if score & 8 > 0 do append(&result, Allergen.Strawberries)
	if score & 16 > 0 do append(&result, Allergen.Tomatoes)
	if score & 32 > 0 do append(&result, Allergen.Chocolate)
	if score & 64 > 0 do append(&result, Allergen.Pollen)
	if score & 128 > 0 do append(&result, Allergen.Cats)

	return result[:]
}
