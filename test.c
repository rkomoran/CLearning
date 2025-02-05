#include <stdio.h>
#include <stdlib.h>

void main (int argc, char ** argv)
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array)/sizeof(int);
    int * ptr = array;

    int i;
    for(i = 0; i < length; i++)
    {
        printf("ptr: %p\n", ptr);
        printf("array %p\n", array);
        printf("\n%ld\n", ptr - array);
        ptr++;
    }
}
