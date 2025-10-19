from typing import Dict, List


def is_paired(input_string: str) -> bool:
    stack: List[str] = []
    whitelist: List[str] = ["(", "{", "["]
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
