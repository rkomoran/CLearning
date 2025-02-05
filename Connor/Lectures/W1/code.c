#include <stdio.h>
#include <stdlib.h>
int func (int c)
{
    int d = c + 5;
    printf("Var c %d\n", c);
    printf("Var d %d\n", d);
    return d;
}
int main (int argc, char ** argv)
{
    int a = 5;
    int b = 17;
    b = func(a++);
    printf("Var a %d\n", a);
    printf("Var b %d\n", b);
    return EXIT_SUCCESS;
}
