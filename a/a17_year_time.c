#include <stdio.h>

int main()
{
    int i;
    scanf("%d", &i);
    if(i<3) printf("winter"); 
    else if(i<6) printf("spring");
    else if(i<9) printf("summer");
    else if(i<12) printf("autumn");
    else printf("winter");
    return 0;
}