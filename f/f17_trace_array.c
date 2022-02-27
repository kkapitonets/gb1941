#include <stdio.h>

#define SIZE 5

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);
	}	
}

int main()
{
	int a[SIZE][SIZE], i1=0;
	
	read_array(SIZE*SIZE, a[0]);
	
	for(int i=0;i<SIZE;i++)
		i1+=a[i][i];
	
	printf("%d", i1);
	
	return 0;
}
