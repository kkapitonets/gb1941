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

int main()
{
	FILE *f2;
	
	char a[SIZE+1];
	
	int i1;
	
	i1=read_string(SIZE+1, a)-1;
	
	f2=fopen("output.txt", "w");
		
	for (int i=0;i<i1;i++) {
	
		if (a[i]==a[i1])
			fprintf(f2, "%d ", i);
	}
	
	fclose(f2);
		
	return 0;
}
