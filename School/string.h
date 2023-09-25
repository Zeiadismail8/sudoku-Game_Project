#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int counter;

int  string_len                (char* str);
void string_print              (char arr[]);
void string_scan               (char* str,int maxsize);
char string_compare_for_search (char*s1,char*s2);
char string_compare_sort       (char *str1, char *str2);
void string_copy               (char *str_original, char *str_copy, int element_number);
void string_copy_charTOint     (char *str, int *num, int element_number);

