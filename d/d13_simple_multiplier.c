#include <stdio.h>

void simple_multiplier(int a, int b){
	
    if (a<2) return;//0, 1 HAVE NOT SIMPLE MULTIPLIER
    
    if (a<4 || b*b>a) printf("%d ", a); //2, 3 IS SIMPLE MULTIPLIER
    
    else if (a%b) simple_multiplier(a,++b); //IS NOT SIPMPLE MULTIPLIER, NEXT CHECK
    
	else { //IS SIPMPLE MULTIPLIER
			printf("%d ", b);
			
			simple_multiplier(a/b,2);//NEW VALUE, NEW CHECK
	}	 
}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	simple_multiplier(i1, 2);
	    
	return 0;
}
