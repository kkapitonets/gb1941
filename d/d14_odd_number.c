#include <stdio.h>

void odd_number(void){
	
	int i1;
	
	scanf("%d", &i1);
	
	if (i1) {
		
		if (i1%2==0) printf("%d ", i1);
		
		odd_number();
	}
	
	return;	
}

int main()
{

	odd_number();
	    
	return 0;
}
