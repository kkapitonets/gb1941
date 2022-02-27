#include <stdio.h>

#define SIZE 10

int count_in_array(int a1, int a2, int* b, int c) {

	int i1=0;
	
	for(int i=a1;i<a2;i++) {
		if (b[i]==c) i1++;
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
	int a[SIZE], i1=0, i2=0, i3;
	
	read_array(SIZE, a);
	
	for(int i=0;i<SIZE;i++) {
		if (i2<(i3=count_in_array(i+1, SIZE, a, a[i]))) {
			i2=i3;
			i1=a[i];
		}	
	}	
	
	printf("%d", i1);
	
	return 0;
}
