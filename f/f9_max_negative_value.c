#include <stdio.h>

#define SIZE 10

int max_negative_value(int a, int* b){
	
	int i1=-1;
	
	for(int i=0;i<a;i++) {
		if (b[i]<0) 
			if (i1==-1 || b[i1]<b[i])
				i1=i;
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
	
	read_array(SIZE, a);
	
	i1=max_negative_value(SIZE, a);
	
	if(i1>-1) {
		i2=a[SIZE-1];
		a[SIZE-1]=a[i1];
		a[i1]=i2;
	}	
	
	print_array(SIZE, a);
	
	return 0;
}
