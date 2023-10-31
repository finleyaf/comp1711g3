#include <stdio.h>

int main()
{
    int a;
    printf("Type a number: ");
    scanf("%d", &a);

    if (a > 0) {
        printf("Number %d is positive\n", a);
    } else if (a = 0) {
        printf("Number %d is 0\n", a);
    } else {
        printf("Number %d is negative\n", a);
    }
    return 0;
}