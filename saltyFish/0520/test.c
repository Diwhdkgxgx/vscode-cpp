#include <stdio.h>
#include <string.h>
int main()
{
    char a[10] = {"a"};
    char b[] = "HHHHHH";

    strcpy(a, b);

    printf("%s\n", a);
    return 0;
}