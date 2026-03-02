def tokenizer(q: str) -> list[str]:
    qt: list[str] = []
    if q.startswith("What is") and q.endswith("?"):
        q = q[8:-1].strip()
    else:
        raise ValueError("syntax error")

    q = q.replace("multiplied by", "multiplied")
    q = q.replace("divided by", "divided")
    qt = q.split()

    return qt


def answer(question: str) -> int:
    tokens = tokenizer(question)

    if not tokens:
        raise ValueError("syntax error")

    try:
        val = int(tokens.pop(0))
    except (ValueError, IndexError):
        raise ValueError("syntax error")

    while tokens:
        if not tokens:
            raise ValueError("syntax error")

        op_token = tokens.pop(0)

        if op_token in ["multiplied", "divided", "plus", "minus"]:
            # It's a recognized operation, now expect an operand
            if not tokens:
                raise ValueError("syntax error")  # Missing operand

            try:
                num = int(tokens.pop(0))
            except (ValueError, IndexError):
                raise ValueError("syntax error")  # Invalid or missing operand

            # Perform the operation
            if op_token == "multiplied":
                val *= num
            elif op_token == "divided":
                val //= num
            elif op_token == "plus":
                val += num
            elif op_token == "minus":
                val -= num
        else:
            # The token is not a recognized operation.
            # Check if it's a number.
            is_number = False
            try:
                # Test if it can be parsed as an integer (positive or negative).
                int(op_token)
                is_number = True
            except ValueError:
                pass  # Not a number

            if is_number:
                # It's a number where an operation was expected.
                raise ValueError("syntax error")
            else:
                # It's neither a recognized operation nor a number.
                raise ValueError("unknown operation")

    return val
