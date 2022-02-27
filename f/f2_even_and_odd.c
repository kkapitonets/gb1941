#include <stdio.h>

#define SIZE 20

void even_and_odd_array(int a1, int a2, int* b) {
	
	int d;

	for(int i1=a1+1;i1<a2;i1++) {
		if(b[i1-1]%2!=0&&b[i1]%2==0) {//CAMPARE LEFT AND RIGNT
			for(int i2=i1;i2>a1;i2--) {//MOVE EVEN TO BEGIN
				if(b[i2-1]%2!=0&&b[i2]%2==0) {
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
	
	even_and_odd_array(0, SIZE, a);
	
	print_array(SIZE, a);
	
	return 0;
}
