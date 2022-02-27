#include <stdio.h>

#define SIZE 10

void swap_min_max(int a, int* b) {
	
	int i1, i2, i3;
	
	if (b[0]<b[1]) {
		i1=0;//INDEX MIN
		i2=1;//INDEX MAX
	}
	else {
		i1=1;//INDEX MIN
		i2=0;//INDEX MAX
	}	

	for(int i=2;i<a;i++) {
		if (b[i1]>b[i])
			i1=i;//INDEX MIN
		if (b[i2]<b[i])
			i2=i;//INDEX MAX
	}	
	
	i3=b[i1];
	b[i1]=b[i2];
	b[i2]=i3;
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
	
	swap_min_max(SIZE, a);
	
	print_array(SIZE, a);
	
	return 0;
}
