#include <stdio.h>

#define SIZE 10

int max_value(int a, int* b){
	
	int m=b[0];
	
	for(int i=1;i<a;i++) {
		if (m<b[i]) m=b[i];
	}
	
	return m;	
}

int _abs(int i1) {
	return i1<0?-i1:i1;
}

int count_abs_value(int a, int* b) {
	
	int i1=0, i2;
	
	i2=max_value(a, b);
	
	for(int i=0;i<a;i++) {
		if (_abs(b[i])>i2)
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
	int a[SIZE];
	
	read_array(SIZE, a);
	
	printf("%d", count_abs_value(SIZE, a));
	
	return 0;
}
