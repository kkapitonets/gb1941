#include <stdio.h>

void sequence(int a){

	if(a>1) sequence(a-1);
	
	printf("%d ", a);  
}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	if(i1>1) sequence(i1-1);
	    
	if(i1>0) printf("%d ", i1);
	    
	return 0;
}
