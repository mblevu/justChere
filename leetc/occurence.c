#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strStr(char *haystack, char *needle);
/**
 * return index of first occurence of needly in haystack
 * return -1 if needle is not in haystack
 * 
 * haystack = leetcode
 * needle = leet 
 * 
*/

int strStr(char *haystack, char *needle)
{
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    int i, j;

    if (needle_len == 0)
    {
        return (0);
    }

    if (haystack_len < needle_len)
    {
        return (-1);
    }
    for (i = 0; i <= haystack_len - needle_len; i++)
    {
        j = 0;
        while (j < needle_len && haystack[i + j] == needle[j])
        {
            j++;
        }
        if (j == needle_len)
        {
            return (i);
        }
    }
    return (-1);

}

int main(void)
{
    char haystack[100] = "leetcode";
    char needle[100] = "leeto";
    int index = strStr(haystack, needle);
    printf("index = %d\n", index);
    return (0);
}