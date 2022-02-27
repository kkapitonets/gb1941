#include <stdio.h>

#define SIZE 8

int main()
{
	int a[SIZE]={0,0,0,0,0,0,0,0}, i1;
	
	do {
		scanf("%d", &i1);
	} while(i1<2||i1>10000);
	
	i1++;
		
	for(int i2=2;i2<i1;i2++) {
		for(int i3=0;i3<SIZE;i3++) {

			if (i2%(i3+2)==0) { 
				a[i3]++;
			}	
		}	
	}	
	
	for(int i3=0;i3<SIZE;i3++) {

		printf("%d %d\n", i3+2, a[i3]);	
	}
	
	return 0;
}
