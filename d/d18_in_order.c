#include <stdio.h>

void in_order_digit(int a){

	int b;
	
	b=a%10;
	
	a=(a-b)/10;
	
	//LIFO
	
	if(a>0) in_order_digit(a);
	
	printf("%d ",b);//FIFO
}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	if(i1>0) in_order_digit(i1);
	
	else printf("0");
	    
	return 0;
}
