#include <stdio.h>

int char_to_digit(unsigned char s1) {
	
	return s1-48;
}	

int main()
{
	unsigned char s1;
	int a[10]={0,0,0,0,0,0,0,0,0,0};
	
	do {

		scanf("%c", &s1);

		if (s1>47 && s1<58)
			a[char_to_digit(s1)]++;
	} while (s1 != '.');
	
	for (int i=0;i<10;i++) {
		if (a[i]) 
			printf("%d %d\n", i, a[i]);
	}		
		
	return 0;
}

