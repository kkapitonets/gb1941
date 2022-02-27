#include <stdio.h>

#define SIZE 10

int is_second_digit_zero(int a) {

	return (a-a%10)%100==0;
}

int second_digit_zero_array(int a, int* b, int* c) {
	
	int i1=0;
	
	for(int i=0;i<a;i++) {
		if(is_second_digit_zero(b[i])) {
			c[i1++]=b[i];
		}	
	}
	
	return i1;				
}

void print_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		printf("%d ", b[i]);
	}	
}	

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);
	}	
}	

int main()
{
	int a[SIZE], b[SIZE], i1=0;
	
	read_array(SIZE, a);
	
	i1=second_digit_zero_array(SIZE, a, b);
	
	print_array(i1, b);
	
	return 0;
}
