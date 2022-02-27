#include <stdio.h>

int fread_stones() {

	FILE *f1; 

	int i1=0, i2;
	
	char s1;

	f1=fopen("input.txt", "r");
	
	do {
		i2=fscanf(f1, "%c", &s1);
		if (s1=='*')//COUNT STONES
			i1++;
	} while (s1!='\0' && i2==1);//ALL LINES
	
	fclose(f1);
	
	return i1;
}	

void fprint_stones(int a) {

	FILE *f2;
	
	int i1=a-1, i2=1; 
	
	f2=fopen("output.txt", "w");
	
	while (i1>i2) {
		i2++;
		i1-=i2;
	}
	
	if (i1 || a<3)
		fprintf(f2, "NO");
	else {
		for(int i=0;i<i2;i++) {
			for(int j=i;j<i2-1;j++)
				fprintf(f2, " ");
			for(int k=0;k<i;k++)
				fprintf(f2, "* ");
			fprintf(f2, "*\n");
		}		
	}
	
	fclose(f2);
}	

int main()
{

	fprint_stones(fread_stones());

	return 0;
}
