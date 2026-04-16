module allergies;

private struct Allergen
{
    uint bit;
    string name;
}

private immutable Allergen[] allergens = [
    Allergen(1, "eggs"),
    Allergen(2, "peanuts"),
    Allergen(4, "shellfish"),
    Allergen(8, "strawberries"),
    Allergen(16, "tomatoes"),
    Allergen(32, "chocolate"),
    Allergen(64, "pollen"),
    Allergen(128, "cats"),
];

class Allergies
{
    private immutable uint score;

    this(immutable uint score)
    {
        this.score = score;
    }

    final bool allergicTo(immutable string item)
    {
        foreach (allergen; allergens)
        {
            if (allergen.name == item)
            {
                return (score & allergen.bit) != 0;
            }
        }

        return false;
    }

    final string[] list()
    {
        string[] result;
        foreach (allergen; allergens)
        {
            if ((score & allergen.bit) != 0)
            {
                result ~= allergen.name;
            }
        }

        return result;
    }
}
