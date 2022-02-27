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

int is_poliander(int a, char * b) {
	
	int i1=a/2;
	
	a--;
	
	for(int i=0;i<i1;i++) {
		if (b[i]!=b[a-i]) return 0;
	}
	
	return 1;	
}

int main()
{
	FILE *f2; 

	char a[SIZE+1];
	
	int i1;
	
	f2=fopen("output.txt", "w");
	
	i1=read_string(SIZE+1, a);
	
	fprintf(f2, "%s", is_poliander(i1, a)?"YES":"NO");

	fclose(f2);
		
	return 0;
}
