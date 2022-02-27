#include <stdio.h>

long power(int a, int b) {

	int i;
	long c=1;
	
	for(i=0;i<b;i++){
		c*=a;
    }	
	
	return c;
}

int main()
{
    int i1, i2;
    
    scanf("%d %d", &i1,&i2);
    
    printf("%ld", power(i1, i2));

    return 0;
}
