#include <stdio.h>

#define SIZE 12

float middle_value(int a, int* b){
	
	float m=0;
	
	for(int i=0;i<a;i++) {
		m+=b[i];
	}
	
	return m/a;	
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
	
	printf("%.2f", middle_value(SIZE, a));
	
	return 0;
}
