#include <stdio.h>

#define SIZE 1000

int read_free_array(int a, int* b) {
	
	int i1=0, i2;
	
	do {
		scanf("%d", &i2);
		if (i2) b[i1++]=i2;
	} while (i2 && i1<a);
	
	return i1;	
}	

void asc_sort_array(int a1, int a2, int* b) {
	
	int d;

	for(int i1=a1+1;i1<a2;i1++) {
		if(b[i1-1]>b[i1]) {
			for(int i2=i1;i2>a1;i2--) {//MOVE LESS TO BEGIN
				if(b[i2-1]>b[i2]) {
					d=b[i2-1];
					b[i2-1]=b[i2];
					b[i2]=d;
				}
			}
		}		
	}				
}

int scan_array(int a, int* b) {
	
	asc_sort_array(0, a, b);
	
	//MISSING MIDDLE
	for (int i=1;i<a;i++) {
		if (b[i]-b[i-1]-1) 
			return b[i-1]+1;
	}	

	//NO WAY TO TELL IF MISSING FIRST OR LAST 
	//FIRST AND LAST HAVE TO BE
	return -1;
}	

int main()
{
	int a[SIZE], i1;
	
	i1=read_free_array(SIZE, a);//FREE SIZE ARRAY
	
	printf("%d", scan_array(i1, a));

	return 0;
}


