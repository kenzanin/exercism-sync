"""
This exercise stub and the test suite contain several enumerated constants.

Enumerated constants can be done with a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""

# Possible sublist categories.
# Change the values as you see fit.
SUBLIST = "SUBLIST"
SUPERLIST = "SUPERLIST"
EQUAL = "EQUAL"
UNEQUAL = "UNEQUAL"


def is_sublist_of(list_a: list, list_b: list) -> bool:
    len_a = len(list_a)
    len_b = len(list_b)

    if len_a == 0:
        return True

    if len_a > len_b:
        return False

    for i in range(len_b - len_a + 1):
        if list_b[i : i + len_a] == list_a:
            return True

    return False


def sublist(list_a: list, list_b: list) -> str:
    if list_a == list_b:
        return EQUAL

    if is_sublist_of(list_a, list_b):
        return SUBLIST

    if is_sublist_of(list_b, list_a):
        return SUPERLIST

    return UNEQUAL
