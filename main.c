#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * swap(char * s);
 
int main(void)
{
    char s[200];
    int count = 0, i;
    printf("vvedit rechenia:");
    scanf("%[^\n]s", s);
    for (i = 0;s[i] != '\0';i++)

    {
        if (s[i] == ' ' && s[i+1] != ' ')
            count++;   
    }
    printf("kilkist sliv: %d\n", count + 1);
    

    printf("%s\n", swap(s));


}
 
char * swap(char * s)
{
    const size_t length = strlen(s);
    char * ch = malloc(length + 1);
 
    strncat(ch, s, length);
    ch[length] = '\0';
 
    char * k = ch;
 
    while (k != NULL)
    {
        char * last = strchr(k, ' ');
 
        if (last != NULL)
        {
            char t = *k;
            *k = *(last - 1);
            *(last - 1) = t;
            k = last + 1;
        }
        else
        {
            char t = *(k);
            *k = *(ch + length - 1);
            *(ch + length - 1) = t;
            k = NULL;
        }
    }
 
    return ch;
}



