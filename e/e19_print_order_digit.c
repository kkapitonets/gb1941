#include <stdio.h>

void print_order_digit(int a) {
	
	int i1, i2;
	
	i1=a%10;
	
	i2=(a-i1)/10;
	
	if (i2>0) print_order_digit(i2);
	
	printf("%d ", i1);

}

int main()
{
	int i1;
	
	scanf("%d", &i1);
	
	if (i1>0) print_order_digit(i1);
	
	else printf("0");
	
	return 0;
}
