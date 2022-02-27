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

void asc_sort_array(int a1, int a2, unsigned char* b) {
	
	unsigned char d;

	for(int i1=a1+1;i1<a2;i1++) {
		if(b[i1-1]>b[i1]) {
			for(int i2=i1;i2>a1;i2--) {//MOVE LESS TO BEGIN
				if(b[i2-1]>b[i2]) {
					d=b[i2-1];
					b[i2-1]=b[i2];
					b[i2]=d;
				}
			}
		}		
	}				
}

int revert(unsigned char* a, int b, int c) {
	
	int i1=b, i2=b-c;
	
	do {
		a[i1++]=a[i2];
	} while (i2--);
	
	return i1;
}

void build_max_polindrom(unsigned char* a) {
	
	int i1=0, i2=0, i3=0, i4=0;
	
	unsigned char b='\0';
	
	do {
		if (a[i1]==a[i2]) //SKIP THE SAME LETTER
			i3++;
		else {//ADD LETTER EVEN TIME
			for (int i=0;i<i3/2;i++) {
				a[i4++]=a[i2];
			}
			if (b=='\0' && i3%2)//FIRST ODD LETTER
				b=a[i2];
			i2=i1;//NEXT LETTER
			i3=1;//RESET COUNTER
		}
		i1++;
	} while (a[i1]!='\0');
	
	for (int i=0;i<i3/2;i++) {//ADD LAST LETTER
		a[i4++]=a[i2];
	}
	if (b=='\0' && i3%2 && a[i2]!='\0')//FIRST ODD LETTER
		b=a[i2];
	
	if (b!='\0') {
		a[i4++]=b;//LAST LETTER ODD TIME
		if (i4>1) 
			i4=revert(a, i4, 2);//REVERT POLINDROM
	}
	else if (i4>0)
		i4=revert(a, i4, 1);//REVERT POLINDROM

	a[i4]='\0';//POLIANDROM END
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
	
	int i1;
	
	i1=fread_string(SIZE+1, a);
	
	asc_sort_array(0, i1, a);
	
	build_max_polindrom(a);
	
	fprint_string(a);

	return 0;
}
