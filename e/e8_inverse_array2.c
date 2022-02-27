#include <stdio.h>

#define SIZE 12

void inverse_array(int a1, int a2, int* b){
	
	int c, d;

	c=(a2-a1)/2;

	a2--;
		
	for(int i=0;i<c;i++) {
		d=b[a1+i];
		b[a1+i]=b[a2-i];
		b[a2-i]=d;
	}
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
	
	inverse_array(0, SIZE/3, a);
	
	inverse_array(SIZE/3, SIZE*2/3, a);
	
	inverse_array(SIZE*2/3, SIZE, a);

	
	print_array(SIZE, a);
	
	return 0;
}
