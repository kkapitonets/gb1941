#include <stdio.h>

#define SIZE 10

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);
	}	
}	

int main()
{
	int a[SIZE], i1=0, m1, i2=0, m2;
	
	read_array(SIZE, a);
	
	m1=m2=a[0];
	
	for(int i=1;i<SIZE;i++) {
		if (m1<a[i]) {
			m1=a[i];//MAX
			i1=i;
		}	
		if (m2>a[i]) {
			m2=a[i];//MIN
			i2=i;
		}	
	}	
	
	printf("%d %d %d %d", i1+1, m1, i2+1, m2);//NUMBER=INDEX+1
	
	return 0;
}
