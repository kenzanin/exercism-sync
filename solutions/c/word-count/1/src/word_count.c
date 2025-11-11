#include "word_count.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdio.h"

int count_words(const char *sentence, word_count_word_t *words)
{
    int lenght = strlen(sentence);

    char var[MAX_WORD_LENGTH] = {0};

    //strncpy(var, sentence, lenght);
    int i = 0;
    for (i = 0; i < lenght; i++)
    {
        var[i] = tolower(sentence[i]);
    }
    strcat(var, " ");

    for (i = 0; i < (int)strlen(var); i++)
    {
        if (var[i] == '\'' && var[i - 1] == ' ')
        {
            var[i] = ' ';
            continue;
        }
        if (var[i] == ' ' && var[i - 1] == '\'')
        {
            var[i - 1] = ' ';
            continue;
        }
        if ((isalnum(var[i]) == 0 && var[i]!='\'') && isblank(var[i]) == 0)
            var[i] = ' ';
    }

//    puts(var);
    char *var01 = strtok(var, " ");
    int var02 = 0;
    while (var01)
    {
        int ii = 0;
        for (i = 0; i < var02; i++)
        {
            if (strcmp(words[i].text, var01) == 0)
            {
                words[i].count += 1;
                ii = 1;
                break;
            }
        }
        if (ii == 1)
        {
            var01 = strtok(NULL, " ");
            continue;
        }
        strcpy(words[var02].text, var01);
        words[var02].count = 1;
        var01 = strtok(NULL, " ");
        var02++;
    }
    return var02;
}
