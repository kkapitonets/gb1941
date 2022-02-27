#include <stdio.h>

#define SIZE 10
	
int scan_even_odd(int a, int* b){

	int i1=0, i2=0;
	
	for(int i=0;i<a;i++) {
		if(b[i]%2)
			i1++;
		else
			i2++;
	}
	
	return i2>i1;	
}

int even(int a) {

	int i1;
	
	i1=a%10;
	
	a=(a-i1)/10;
	
	if (i1%2==0) 
		i1=1;//ODD IS NOT MULTIPLYER FOR EVEN
	
	if (a>0) 
		return i1*even(a);
	else
		return i1;
}

void product_even(int a, int* b) {

	for(int i=0;i<a;i++) {
		if(b[i]%2)
			b[i]=even(b[i]);
	}	
}

int odd(int a) {

	int i1;
	
	i1=a%10;
	
	a=(a-i1)/10;
	
	if (i1%2) 
		i1=1;//EVEN IS NOT MULTIPLYER FOR ODD
	
	if (a>0) 
		return i1*odd(a);
	else
		return i1;
}

void product_odd(int a, int* b) {

	for(int i=0;i<a;i++) {
		if(b[i]%2==0)
			b[i]=odd(b[i]);
	}	
}

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);
	}	
}

void print_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		printf("%d ", b[i]);
	}	
}	

int main()
{
	int a[SIZE];
	
	read_array(SIZE, a);
	
	if (scan_even_odd(SIZE, a))
		product_even(SIZE, a);
	else
		product_odd(SIZE, a);	
	
	print_array(SIZE, a);
	
	return 0;
}
