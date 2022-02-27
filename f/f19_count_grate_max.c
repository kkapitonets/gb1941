#include <stdio.h>

#define SIZE 5

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);//ROW1, ROW2,...
	}	
}

float trace_am_value(int a, int (*b)[a]){//FINT 3
	
	float m=0;
	
	for(int i=0;i<a;i++) {
		 m+=b[i][i];
	}
	
	return m/a;	
}

int count_grate(int a, int (*b)[a]) {
	
	int i1=0;
	
	float i2;

	i2=trace_am_value(a, b);
	
	for(int i=0;i<a*a;i++) {
		if (b[0][i]>0 && b[0][i]>i2)//FINT 2
			i1++;
	}
	
	return i1;
}

int main()
{
	int a[SIZE][SIZE];
	
	read_array(SIZE*SIZE, a[0]);//FINT 1
	
	printf("%d", count_grate(SIZE, a));
	
	return 0;
}
