//c中运算式左左值只有指针时才行，而c++中运算式可以做左值
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