#include <stdio.h>

unsigned long long power2(int a) {

	unsigned long long b=1;
	
	return b<<a;
}

int main()
{
    int i1;
    
    scanf("%d", &i1);
    
    printf("%llu", power2(i1-1));

    return 0;
}
