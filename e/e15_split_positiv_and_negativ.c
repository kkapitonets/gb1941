#include <stdio.h>

#define SIZE 10

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
	int a[SIZE], b[SIZE], c[SIZE], i1=0, i2=0;
	
	read_array(SIZE, a);
	
	for(int i=0;i<SIZE;i++) {
		if (a[i]>0) b[i1++]=a[i];
		if (a[i]<0) c[i2++]=a[i];
	}	
	
	print_array(i1, b);

	print_array(i2, c);

	
	return 0;
}
