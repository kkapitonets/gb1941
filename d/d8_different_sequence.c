#include <stdio.h>

void different_sequence(int a, int b){

	if(a>b) {

		printf("%d ", a);//FIFO
		  
		different_sequence(a-1,b);
	}
	else if(a<b) {

		different_sequence(a,b-1);

		printf("%d ", b); //LIFO 
	}
	else printf("%d ", b);//LAST 	
}

int main()
{
    int i1, i2;
    
    scanf("%d %d", &i1, &i2);

	different_sequence(i1, i2);
	    
	return 0;
}
