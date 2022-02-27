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

void pair_letter(unsigned char* a) {
	
	int i1=0, i2=0;//INDEX TO CHANGE
	
	char b;
	
	do {
		
		if (i1==i2) {
			if (a[i1]==' ')
				i2++;//SKIP BLANK FOR FIRST
		}		
		else if (a[i1]!=' ') {//SKIP BLANK FOR SECOND
			b=a[i1];
			a[i1]=a[i2];
			a[i2]=b;
			i2=i1+1;
		}	
		i1++; 	
	} while (a[i1]!='\0');
}

void fprint_string(unsigned char* a) {

	FILE *f2; 
	
	f2=fopen("output.txt", "w");

	fprintf(f2, "%s", a);

	fclose(f2);
}	

int main()
{
	unsigned char a[SIZE+1];
	
	fread_string(SIZE+1, a);
	
	pair_letter(a);
	
	fprint_string(a);

	return 0;
}
