#include <stdio.h>

#define SIZE 100

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);
	}	
}	

void zero_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		b[i]=0;
	}	
}	

int main()
{
	int a[SIZE], b[SIZE], i1=0, i2=0;
	
	read_array(SIZE, a);
	
	zero_array(SIZE, b);
	
	for (int i=0;i<SIZE;i++) {
		if (a[i]!=i2) {
			i1++;//NEXT SET INDEX
			i2=a[i];//SET TYPE
		}
		b[i1]++;//SET SIZE		
	}	
	
	printf("[");
	
	for (int i=0;i<i1;i++) {
		printf("%d,", b[i]);
	}	
	
	printf("%d]", b[i1]);

	return 0;
}


