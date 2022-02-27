#include <stdio.h>

#define SIZE 10

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);//ROW1, ROW2,...
	}	
}

int max_value(int a, int* b){
	
	int m=b[0];
	
	for(int i=1;i<a;i++) {
		if (m<b[i]) m=b[i];
	}
	
	return m;	
}

int main()
{
	int a[SIZE][SIZE], i1=0;
	
	read_array(SIZE*SIZE, a[0]);
	
	for(int i=0;i<SIZE;i++) {
		i1+=max_value(SIZE, a[i]);//ROW1, ROW2,...
	}	
	
	printf("%d", i1);
	
	return 0;
}
