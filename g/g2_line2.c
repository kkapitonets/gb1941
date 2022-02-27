#include <stdio.h>

int main()
{
	FILE *f1, *f2;
	
	unsigned char a='A';
	
	int i1;
	
	f1=fopen("input.txt", "r");
	
	f2=fopen("output.txt", "w");
	
	fscanf(f1, "%d", &i1);
	
	for (int i=0;i<i1;i++) {
	
		if (i%2==0) {
			fprintf(f2, "%c", a);
			a+=1;
		}	
		else {
			fprintf(f2, "%d", i%8+1);
		}	
	}
	
	fclose(f1);
	
	fclose(f2);
		
	return 0;
}
