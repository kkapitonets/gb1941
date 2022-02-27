#include <stdio.h>

int main()
{
    int i,j1,j2,j3,j4;
    scanf("%d", &i);
    j1=i%10;
    i=(i-j1)/10;
    j2=i%10;
    j4=j1;
    if(j2>j4) j4=j2;
    i=(i-j2)/10;
    j3=i%10;
    if(j3>j4) j4=j3;
    printf("%d", j4);
    return 0;
}