def response(hey_bob: str) -> str:
    hey_bob = hey_bob.strip()
    is_question = hey_bob.endswith("?")
    is_yelling = hey_bob.isupper() and any(c.isalpha() for c in hey_bob)

    if len(hey_bob) == 0:
        return "Fine. Be that way!"
    if is_yelling and not is_question:
        return "Whoa, chill out!"
    elif is_question and not is_yelling:
        return "Sure."
    elif is_yelling and is_question:
        return "Calm down, I know what I'm doing!"
    else:
        return "Whatever."

    return ""
