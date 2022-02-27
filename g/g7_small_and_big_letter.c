#include <stdio.h>

#define SIZE 10000

int read_string(int a, char * b) {

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
	FILE *f2; 

	char a[SIZE+1];
	
	int i1=0, i2=0, i3=0;
	
	f2=fopen("output.txt", "w");
	
	read_string(SIZE+1, a);
	
	while (a[i3]!='\0') {

		if (a[i3]>96 && a[i3]<123)//SMALL LETTER
			i1++;
		if (a[i3]>64 && a[i3]<91)//BIG LETTER
			i2++;
	
		i3++;
	}
	
	fprintf(f2, "%d %d", i1, i2);

	fclose(f2);
		
	return 0;
}
