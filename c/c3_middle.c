#include <stdio.h>

unsigned middle(unsigned a, unsigned b) {

	return (a+b)/2;
}

int main()
{
    unsigned i1, i2;
    
    scanf("%u %u", &i1,&i2);
    
    printf("%u", middle(i1, i2));

    return 0;
}
