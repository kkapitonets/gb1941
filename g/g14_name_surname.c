#include <stdio.h>

#define SIZE 100

int main()
{
	unsigned char a[SIZE+1], b[SIZE+1];
	
	FILE *f1, *f2; 

	f1=fopen("input.txt", "r");
	
	fscanf(f1, "%s %s", a, b);
	
	fclose(f1);
	
	f2=fopen("output.txt", "w");

	fprintf(f2, "Hello, %s %s!", b, a);
	
	fclose(f2);

	return 0;
}
