#include <stdio.h>

int main()
{
    int i1,i2, i3;
    scanf("%d %d %d", &i1,&i2,&i3);
    if(i2>i1&&i3>i2) printf("YES"); else printf("NO");
    return 0;
}