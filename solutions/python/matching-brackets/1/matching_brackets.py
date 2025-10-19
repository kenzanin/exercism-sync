from typing import Dict


def is_paired(input_string: str) -> bool:
    stack: list = []
    whitelist: list = ["(", "{", "["]
    bracket_map: Dict[str, str] = {")": "(", "}": "{", "]": "["}
    for ch in input_string:
        if ch in bracket_map:
            if stack and stack[-1] == bracket_map[ch]:
                stack.pop()
            else:
                return False
        elif ch in whitelist:
            stack.append(ch)

    return len(stack) == 0


if __name__ == "__main__":
    print(
        is_paired(
            "\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ \\mathrm{e}^{x} &... x^2 \\end{array}\\right)"
        )
    )
