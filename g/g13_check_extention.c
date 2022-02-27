#include <stdio.h>

#define SIZE 1000

int fread_string(int a, unsigned char* b) {

	FILE *f1; 

	int i1=0, i2;

	f1=fopen("input.txt", "r");
	
	do {
		i2=fscanf(f1, "%c", &b[i1]);
	} while (b[i1++]!='\n' && i2==1 && i1<a);
	
	if (i2) i1--;
	
	b[i1]='\0';

	fclose(f1);
	
	return i1;
}	

int main()
{
	unsigned char a[SIZE+1];
	
	int i1;
	
	FILE *f2; 
	
	f2=fopen("output.txt", "w");

	i1=fread_string(SIZE+1, a);
	
	do {
		i1--;	
	} while (a[i1]!='.' && a[i1]!='/');
	
	if (a[i1]=='.')
		a[i1]='\0';
	
	fprintf(f2, "%s.html", a);
	
	fclose(f2);

	return 0;
}
