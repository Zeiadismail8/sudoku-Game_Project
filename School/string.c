#include "string.h"

int string_len(char*str)
{
    for(counter=0; str[counter]; counter++);
    return counter;
}

void string_print(char arr[])
{
    for(counter=0; arr[counter]!=0; counter++)
    {
        printf("%c",arr[counter]);
    }
    printf("\n");
}

void string_scan(char* str,int maxsize)
{
    counter=0;
    fflush(stdin);
    scanf("%c",&str[counter]);
    for(; str[counter]!='\n'&&counter<maxsize-1;)
    {
        counter++;
        scanf("%c",&str[counter]);
    }
    str[counter]=0;
}

char string_compare_for_search(char* str1,char* str2)
{
    int l1=string_len(str1);
    int l2=string_len(str2);
    if(l1==l2)
    {
        for(counter=0; str1[counter]; counter++)
        {
            if(str1[counter] != str2[counter] && str1[counter] != str2[counter] - ('a'-'A') && str1[counter] != str2[counter] + ('a'-'A'))
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

char string_compare_sort(char *str1, char *str2)
{
    int c1, c2;
    for(counter = 0; str1[counter] && str2[counter]; counter++)
    {
        c1 = str1[counter];
        c2 = str2[counter];
        if(c1 >= 'a' && c1 <= 'z')
        {
            c1 -= 32;
        }
        if(c2 >= 'a' && c2 <= 'z')
        {
            c2 -= 32;
        }
        if(c1 > c2)
        {
            return 1;
        }
        else if(c1 < c2)
        {
            return -1;
        }
    }
    if(!str1[counter] && str2[counter])
    {
        return -1;
    }
    else if(str1[counter] && !str2[counter])
    {
        return 1;
    }
    return 0;
}

void string_copy(char *str_original, char *str_copy, int element_number)
{
    for(int counter = 0; counter < element_number && str_original[counter]; counter++)
    {
        str_copy[counter] = str_original[counter];
    }
}

void string_copy_charTOint(char *str, int *num, int element_number)
{
    for(int counter = 0; counter < element_number && (str[counter] >= '0' && str[counter] <= '9'); counter++)
    {
        *num = *num * 10 + (str[counter] - '0');
    }
}




