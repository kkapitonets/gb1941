#include <stdio.h>

#define SIZE 100

int max_value(int a, int* b){
	
	int m=b[0];
	
	for(int i=1;i<a;i++) {
		if (m<b[i]) m=b[i];
	}
	
	return m;	
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
	
	printf("%d", max_value(SIZE, a));
	
	return 0;
}


