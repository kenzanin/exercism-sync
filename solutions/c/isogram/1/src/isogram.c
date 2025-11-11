#include "isogram.h"
#include "string.h"
#include "ctype.h"


bool is_isogram(const char phrase[])
{
    int length;
    if(phrase==NULL)return false;

    for(length=0;phrase[length]!='\0';length++);
    if (length==0)return true;

    int i;
    for(i=0;i<length;i++){
        int ii;
        if( isalpha(phrase[i])==false)continue;
        for(ii=i+1;ii<length;ii++)
        {
            if(tolower(phrase[i])==tolower(phrase[ii])) return false;
        }
    }

    return true;
}