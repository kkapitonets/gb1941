#include <stdio.h>

#define SIZE 30

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);
	}	
}	

int main()
{
	int a[SIZE], m1, m2;
	
	read_array(SIZE, a);
	
	if(a[0]<a[1]) {
		m1=0;//INDEX MIN1
		m2=1;//INDEX MIN2
	}
	
	for(int i=2;i<SIZE;i++) {
		if (a[m1]>a[i]) {
			m2=m1;//INDEX MIN2
			m1=i;//INDEX MIN1
		}
		else if	(a[m2]>a[i]) {
			m2=i;//INDEX MIN2
		}
	}	
	
	printf("%d %d", m1<m2?m1:m2, m1<m2?m2:m1);//INDEX MIN1 AND MIN2
	
	return 0;
}
