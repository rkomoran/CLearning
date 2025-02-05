#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main (int argc, char ** argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Enter two strings\n");
    }

    char * ptr;
    int count = 0;
    
    ptr = argv[1];
    do
    {
        ptr = strstr(ptr, argv[2]);

        if (ptr != NULL)
        {
            printf("%s\n", ptr);
            count++;
            ptr++;
        }
    } while(ptr != NULL);
    
}
