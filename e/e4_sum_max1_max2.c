#include <stdio.h>

#define SIZE 10

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);
	}	
}	

int main()
{
	int a[SIZE], m1, m2;
	
	read_array(SIZE, a);
	
	if(a[0]>a[1]) {
		m1=a[0];
		m2=a[1];
	}
	else {
		m1=a[1];
		m2=a[0];
	}
	
	for(int i=2;i<SIZE;i++) {
		if (m1<a[i]) {
			m2=m1;//MAX2
			m1=a[i];//MAX1
		}
		else if	(m2<a[i]) {
			m2=a[i];//MAX2
		}
	}	
	
	printf("%d", m1+m2);
	
	return 0;
}
