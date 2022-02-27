#include <stdio.h>

int main()
{
    int i,j1,j2,j3;
    scanf("%d", &i);
    j1=i%10;
    i=(i-j1)/10;
    j2=i%10;
    i=(i-j2)/10;
    j3=i%10;
    printf("%d", j1+j2+j3);
    return 0;
}