#include <stdio.h>

int main()
{
    int i1,i2;
    scanf("%d %d", &i1,&i2);
    if(i1>i2) printf("Above"); 
    else if(i1<i2) printf("Less");
    else printf("Equal");
    return 0;
}