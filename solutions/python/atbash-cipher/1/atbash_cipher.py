from typing import List


def _helper(text: str) -> str:
    result: List = []
    for char in text.lower():
        if char.isalpha():
            result.append(chr(ord("a") + ord("z") - ord(char)))
        elif char.isdigit():
            result.append(char)
    return "".join(result)


def encode(plain_text: str) -> str:
    ciphered_text = _helper(plain_text)
    return " ".join(ciphered_text[i : i + 5] for i in range(0, len(ciphered_text), 5))


def decode(ciphered_text: str) -> str:
    return _helper(ciphered_text)
