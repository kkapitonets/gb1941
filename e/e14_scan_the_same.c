#include <stdio.h>

#define SIZE 10


int is_exist(int a1, int a2, int* b, int c) {
	
	for(int i=a1;i<a2;i++) {
		if(b[i]==c) return 1;
	}
	
	return 0;
}	

int scan_the_same_array(int a, int* b, int* c) {
	
	int i1=0;
	
	for(int i=0;i<a;i++) {
		if(is_exist(i+1, a, b, b[i]) && !is_exist(0, i1, c, b[i])) {
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
	
	i1=scan_the_same_array(SIZE, a, b);
	
	print_array(i1, b);
	
	return 0;
}
