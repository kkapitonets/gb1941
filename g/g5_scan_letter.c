#include <stdio.h>

#define SIZE 1000

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

void scan_letter(char * a) {
	
	int i1=0;
	
	while (a[i1]!= '\0') {
		if (a[i1]=='a')
			a[i1]='b';
		else if (a[i1]=='b')
			a[i1]='a';
		else if (a[i1]=='A')
			a[i1]='B';
		else if (a[i1]=='B')
			a[i1]='A';
		i1++;	
	}
}

int main()
{
	FILE *f2; 

	char a[SIZE+1];
	
	f2=fopen("output.txt", "w");
	
	read_string(SIZE+1, a);
	
	scan_letter(a);

	fprintf(f2, "%s", a);

	fclose(f2);
		
	return 0;
}
