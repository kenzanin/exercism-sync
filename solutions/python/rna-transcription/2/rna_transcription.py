from typing import Dict, List


def to_rna(dna_strand) -> str:
    rna: Dict[str, str] = {"G": "C", "C": "G", "T": "A", "A": "U"}
    ret: List[str] = []
    for ch in dna_strand:
        if ch in rna:
            ret.append(rna[ch])
        else:
            ret.append(ch)
    return "".join(ret)
