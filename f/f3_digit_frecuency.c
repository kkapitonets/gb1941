#include <stdio.h>

#define SIZE 1000

int char_to_digit(unsigned char s1) {
	
	return s1-48;
}	

int main()
{
	unsigned char s1[SIZE+1];
	
	int a[10]={0,0,0,0,0,0,0,0,0,0}, i1=0;
	
	scanf("%s", s1);
	
	do {
		a[char_to_digit(s1[i1])]++;
	} while (s1[i1++]);
	
	for (int i=0;i<10;i++) {
		if (a[i]) 
			printf("%d %d\n", i, a[i]);
	}		
		
	return 0;
}

