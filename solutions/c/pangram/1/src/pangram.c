#include "pangram.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"

bool is_pangram(const char *sentence)
{
    if (sentence == NULL)
        return false;
    if (*sentence == '\0')
        return false;

    int lenght = strlen(sentence);
    char *var = malloc(lenght);
    if (var == NULL)
        return false;

    int i = 0;
    for (i = 0; i < lenght; i++)
    {
        var[i] = tolower(sentence[i]);
        if (isalpha(var[i]) == 0)
            var[i] = ' ';
    }

    for (i = 'a'; i < 'z'; i++)
    {
        if (strchr(var, i) == NULL)
        {
            free(var);
            return false;
        }
    }

    free(var);
    return true;
}
