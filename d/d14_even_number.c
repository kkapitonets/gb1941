#include <stdio.h>

void even_number(void){
	
	int i1;
	
	scanf("%d", &i1);
	
	if (i1) {
		
		if (i1%2) printf("%d ", i1);
		
		even_number();
	}
	
	return;	
}

int main()
{

	even_number();
	    
	return 0;
}
