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

int scan_exist(unsigned char * a, char b) {
	
	int i1=0, i2=0;
	
	while (a[i1]!= '\0') {
		if (a[i1]==b) {
			return 1;
		}
		i1++;	
	}
	
	return i2;
}

void zip_string(unsigned char* a) {
	
	int i1=0, i2=0;
	
	char b;
	
	do {
		b=a[i1];
		a[i2]='\0';
		if(b!=' ' && !scan_exist(a, b)) {
			a[i2]=b;
			i2++;
		}	
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
	
	zip_string(a);
	
	fprint_string(a);

	return 0;
}
