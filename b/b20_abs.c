#include <stdio.h>

int abs(int a) {

	return a>0?a:-a;
}

int main()
{
    int i1;
    
    scanf("%d", &i1);
    
    printf("%d", abs(i1));

    return 0;
}
