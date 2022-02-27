#include <stdio.h>

#define SIZE 10

int count_interval(int a, int* b, int c, int d) {
	
	int i1=0;
	
	c--;
	
	d++;
	
	for(int i=0;i<a;i++) {
		if (b[i]>c && b[i]<d)
			i1++;
	}
		
	return i1;
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
	int a[SIZE], i1, i2;
	
	scanf("%d %d", &i1, &i2);
	
	read_array(SIZE, a);
	
	printf("%d", count_interval(SIZE, a, i1<i2?i1:i2, i1<i2?i2:i1));
	
	return 0;
}
