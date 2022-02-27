#include <stdio.h>

#define SIZE 10

void sort_last_digit_array(int a, int* b){
	
	int d;

	for(int i1=1;i1<a;i1++) {
		if(b[i1-1]%10>b[i1]%10) {
			for(int i2=i1;i2>0;i2--) {
				if(b[i2-1]%10>b[i2]%10) {
					d=b[i2-1];
					b[i2-1]=b[i2];
					b[i2]=d;
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
	
	sort_last_digit_array(SIZE, a);
	
	print_array(SIZE, a);
	
	return 0;
}
