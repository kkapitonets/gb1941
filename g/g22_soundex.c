#include <stdio.h>

#define SIZE 20

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

int in_set(char a, char* b) {

	int i1=0;

	while (b[i1]!='\0') {
		if(b[i1++]==a)
			return 1;
	}
	
	return 0;	
}

void zip_word(unsigned char* a) {
	
	int i1=1, i2=1;
	
	do {

		if (in_set(a[i1], "bfpv") && a[i2-1]!='1')
			a[i2++]='1';
		else if (in_set(a[i1], "cgjkqsxz") && a[i2-1]!='2')
			a[i2++]='2';
		else if (in_set(a[i1], "dt") && a[i2-1]!='3')
			a[i2++]='3';
		else if (in_set(a[i1], "l") && a[i2-1]!='4')
			a[i2++]='4';
		else if (in_set(a[i1], "mn") && a[i2-1]!='5')
			a[i2++]='5';
		else if (in_set(a[i1], "r") && a[i2-1]!='6')
			a[i2++]='6';

		i1++;
	} while (a[i1]!='\0' && i2<4);
	
	while (i2<4) {
		a[i2++]='0';
	} 
	 		
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
	
	zip_word(a);
	
	fprint_string(a);

	return 0;
}
