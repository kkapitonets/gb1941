#include <stdio.h>

#define SIZE 12

void right_shift_array(int a, int* b){
	
	int d;

	d=b[a-1];

	for(int i=a-1;i>0;i--) {
		b[i]=b[i-1];
	}

	b[0]=d;
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
	int a[SIZE];
	
	read_array(SIZE, a);
	
	for (int i=0;i<4;i++) 
		right_shift_array(SIZE, a);
	
	print_array(SIZE, a);
	
	return 0;
}
