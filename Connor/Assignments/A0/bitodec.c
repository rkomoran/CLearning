#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int bin2Dec(int n)
{
    int dec = 0;
    int base = 1;

    while (n > 0)
    {
        int digit = n % 10;
        dec += base * digit;
        base *= 2;
        n = n/10;
    }

    return dec;
}

int main (int argc, char ** argv)
{
    if (argc == 1)
    {
        fprintf(stderr, "Must supply a num\n");
        return EXIT_FAILURE;
    }
    int num = (int) strtol(argv[1], NULL, 10);
    int res = bin2Dec(num);

    printf("Num = %d\n", res);

    return EXIT_SUCCESS;
}
