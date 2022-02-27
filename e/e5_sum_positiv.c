#include <stdio.h>

#define SIZE 10

int sum_positiv(int a, int* b) {
	
	int s=0;
	
	for(int i=0;i<a;i++) {
		if (b[i]>0) s+=b[i];
	}
	
	return s;	
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
	
	printf("%d", sum_positiv(SIZE, a));
	
	return 0;
}
