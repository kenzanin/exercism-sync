package protein

import "errors"

var ErrStop = errors.New("err Stop")
var ErrInvalidBase = errors.New("err base")

func FromRNA(rna string) ([]string, error) {
	result := []string{}
	ii := 3
	for i := 0; i < len(rna); i += 3 {
		codon := ""
		for iii := i; iii < ii; iii++ {
			codon += string(rna[iii])
		}
		protein, e := FromCodon(codon)
		if e == ErrStop {
			break
		} else if e == ErrInvalidBase {
			return result, e
		}
		result = append(result, protein)

		ii += 3
	}
	return result, nil
}

func FromCodon(codon string) (string, error) {
	result := ""
	switch codon {
	/*		Codon                 | Protein
			:---                  | :---
			AUG                   | Methionine
			UUU, UUC              | Phenylalanine
			UUA, UUG              | Leucine
			UCU, UCC, UCA, UCG    | Serine
			UAU, UAC              | Tyrosine
			UGU, UGC              | Cysteine
			UGG                   | Tryptophan
			UAA, UAG, UGA         | STOP
	*/
	case "AUG":
		result = "Methionine"
	case "UUU", "UUC":
		result = "Phenylalanine"
	case "UCU", "UCC", "UCA", "UCG":
		result = "Serine"
	case "UAU", "UAC":
		result = "Tyrosine"
	case "UGU", "UGC":
		result = "Cysteine"
	case "UGG":
		result = "Tryptophan"
	case "UAA", "UAG", "UGA":
		return "", ErrStop
	case "UUA", "UUG":
		result = "Leucine"
	default:
		return "", ErrInvalidBase
	}

	return result, nil
}
