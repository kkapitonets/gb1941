#include <stdio.h>

int main()
{
    int i1, i2;
    scanf("%d %d", &i1,&i2);
    if(i1>i2) printf("%d %d", i2,i1); else printf("%d %d", i1,i2);
    return 0;
}