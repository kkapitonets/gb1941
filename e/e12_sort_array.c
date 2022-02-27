#include <stdio.h>

#define SIZE 10

void asc_sort_array(int a1, int a2, int* b) {
	
	int d;

	for(int i1=a1+1;i1<a2;i1++) {
		if(b[i1-1]>b[i1]) {
			for(int i2=i1;i2>a1;i2--) {//MOVE LESS TO BEGIN
				if(b[i2-1]>b[i2]) {
					d=b[i2-1];
					b[i2-1]=b[i2];
					b[i2]=d;
				}
			}
		}		
	}				
}

void disc_sort_array(int a1, int a2, int* b) {
	
	int d;

	for(int i1=a1+1;i1<a2;i1++) {
		if(b[i1-1]<b[i1]) {
			for(int i2=i1;i2>a1;i2--) {//MOVE GRATE TO BEGIN
				if(b[i2-1]<b[i2]) {
					d=b[i2];
					b[i2]=b[i2-1];
					b[i2-1]=d;
				}
			}
		}		
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
	
	asc_sort_array(0, SIZE/2, a);
	
	disc_sort_array(SIZE/2, SIZE, a);
	
	print_array(SIZE, a);
	
	return 0;
}
