#include <stdio.h>

unsigned long long factorial(int a) {

	unsigned long long b=1;
	
  	for(int i=2;i<a;i++){
		b*=i;
	}	
  	
	return a?b*a:b;
}

int main()
{
    int i1;
    
	scanf("%d", &i1);
	
	printf("%llu", factorial(i1));
	
    return 0;
}
