#include <stdio.h>
int main()
{
    int x = 10, y = 20;
    int *a, *b;
    a = &x, b = &y;
    *(a < b ? a : b) = 50;
    printf("%d\n%d\n", a, b);
    printf("%d\n%d", x, y);
}