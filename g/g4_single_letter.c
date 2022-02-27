#include <stdio.h>

#define SIZE 100

int scan_single(char * a, char b) {
	
	int i1=0, i2=0;
	
	while (a[i1]!= '\0') {
		if (a[i1]==b) {
			if (++i2>1) 
				return 0;
		}
		i1++;	
	}
	
	return i2;
}

int main()
{
	FILE *f1, *f2; 

	int i1=0;
	
	char a[SIZE+1], b[SIZE+1];
	
	f1=fopen("input.txt", "r");

	f2=fopen("output.txt", "w");
	
	fscanf(f1, "%s %s", a, b);

	while (a[i1]!= '\0') {
		if (scan_single(a, a[i1]) && scan_single(b, a[i1])) {
			fprintf(f2, "%c ", a[i1]);
		}
		i1++;	
	}

	fclose(f1);

	fclose(f2);
		
	return 0;
}
