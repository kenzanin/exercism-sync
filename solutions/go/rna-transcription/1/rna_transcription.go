package strand

func ToRNA(dna string) string {

	rnaMap := map[rune]rune{
		//* `G` -> `C`
		//* `C` -> `G`
		//* `T` -> `A`
		//* `A` -> `U`
		'G': 'C',
		'C': 'G',
		'T': 'A',
		'A': 'U',
	}
	dna_r := []rune(dna)
	for i, v := range dna_r {
		dna_r[i] = rnaMap[v]
	}

	return string(dna_r)
}
