#include <stdio.h>

int main()
{
    float a,b,c;
    float p;
    scanf("%f %f %f", &a,&b,&c);
    p=(a+b+c)/2;
    if((p-a)*(p-b)*(p-c)>0) printf("YES"); else printf("NO");
    return 0;
}