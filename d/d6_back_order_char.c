#include <stdio.h>

void back_order_char(void){

	char a;

	scanf("%c", &a);
	
	if(a!='.') {
		//FIFO
		back_order_char();
		//LIFO
		printf("%c", a);
	}	
	
}

int main()
{

	back_order_char();
	    
	return 0;
}
