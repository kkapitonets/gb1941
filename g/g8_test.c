#include <stdio.h>

#define SIZE 1000

int main() {

	FILE *f1; 
	
	char a[SIZE+1];

	int i1=0, i2;

	f1=fopen("input.txt", "r");
	
	do {
		if((i2=fscanf(f1, "%[0-9]", a))>0)
			i1+=i2;
		printf("%s %d", a, i2); 
	} while (i2>0);
	
	a[i1]='\0';
	
	printf("%s", a);

	fclose(f1);
	
	return i1;
}	

