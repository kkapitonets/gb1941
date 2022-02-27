#include <stdio.h>

int main()
{
    int i1, i2, i3, i4;
    scanf("%d %d %d", &i1,&i2,&i3);
    i4=i1;
    if(i2>i4) i4=i2;
    if(i3>i4) i4=i3;
    printf("%d", i4);
    return 0;
}