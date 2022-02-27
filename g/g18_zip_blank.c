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

void zip_blank(unsigned char* a) {
	
	int i1=0, i2=0, i3=0;
	
	do {
		
		if (a[i1]!=' ') {//SKIP BLANK
			if (i2==0 || i3==0) {//BEGIN OR IF BLANK IS NOT EXIST
				a[i2++]=a[i1];
				i3=0;
			}
			else if (i3) {//ONLY ONE BLANK IF BLANK EXISTS
				a[i2++]=' ';
				a[i2++]=a[i1];
				i3=0;
			}		
		}
		else
			i3++;//COUNT BLANK

		i1++;
	} while (a[i1]!='\0');
	
	a[i2]='\0';
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
	
	zip_blank(a);
	
	fprint_string(a);

	return 0;
}
