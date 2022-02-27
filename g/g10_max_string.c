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

int split_string(unsigned char * a) {
	
	int i1=0;
	
	while (a[i1]!= ' ' && a[i1]!= '\0' ) {
		i1++;	
	}
	
	return i1;
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
	
	int i1=0, i2=0, i3=0, i4=0;
	
	fread_string(SIZE+1, a);
	
	do {
			
		if (i4!=0) {
			a[i1]='\0';
			i1++;
		}	
		
		i2=split_string(&a[i1]);
		
		if (i4==0 || i4<i2) {
			i3=i1;//BEGIN
			i4=i2;//LENGHT
		}
		
		i1+=i2;	
	} while (a[i1]!='\0');
	
	fprint_string(&a[i3]);

	return 0;
}
