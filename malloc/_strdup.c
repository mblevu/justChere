#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_strdup(char *str);

int main()
{
    char *str = "hello";
    char *copy = _strdup(str);

    printf("original: %s\n", str);
    printf("Copied: %s\n", copy);
   
    free(copy);

    return 0;

}
/**
 * check if string is empty
 * allocate memory for the copied string
 * copy string using strcopy
 * return copy
*/
char *_strdup(char *str)
{
   if (str == NULL)
   {
        return (NULL);
   }

   char *copy = malloc(strlen(str) + 1);

   if (copy == NULL)
   {
        return (NULL);
   }
   strcpy(copy, str);
   return (copy);
}

