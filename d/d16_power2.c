#include <stdio.h>

int is_power2(int a){
	
	int b;
	
	b=a%2;
	
	a=(a-b)/2;
	
	if (a) {
		
		if (b) return 0; //MIDDLE DIGIT IS 1
		
		return is_power2(a); //CHECK NEXT DIGIT
	}
	else return 1; //ALL MIDDLE DIGIT IS ZERO
	
}

int main()
{
	int i1;
	
	scanf("%d", &i1);
	
	printf("%s", is_power2(i1) && i1>0?"YES":"NO"); 
	    
	return 0;
}
