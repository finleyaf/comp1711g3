#include <stdio.h>

int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main()
{
    int a = 2;
    int b = 3;
    int ans = add(a, b);
    printf("%d\n", ans);
}