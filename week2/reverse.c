#include <stdio.h>

int main() 
{
    char greet[6];
    printf("Say hello\n");
    scanf("%s", greet);

    int i;
    for (i = 5; i>=0; i--) {
        printf("%c", greet[i]);
    }
    return 0;
}