#include <stdio.h>

#define SIZE 100
	
int main()
{
	FILE *f1, *f2;
	
	char a[SIZE+1];
	
	int i1=0, i2;
	
	f1=fopen("input.txt", "r");
	
	f2=fopen("output.txt", "w");
	
	do {
		i2=fscanf(f1, "%c", &a[i1]);
	} while (a[i1++]!='\n' && i2==1);
	
	if (i2) i1--;
	
	a[i1]='\0';
	
	fprintf(f2, "%s, %s, %s %d", a, a, a, i1);
	
	fclose(f1);
	
	fclose(f2);
		
	return 0;
}
