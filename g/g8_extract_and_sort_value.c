#include <stdio.h>

#define SIZE 1000

void asc_sort_array(int a, int* b) {
	
	int d;

	for(int i1=1;i1<a;i1++) {
		if(b[i1-1]>b[i1]) {
			for(int i2=i1;i2>0;i2--) {//MOVE LESS TO BEGIN
				if(b[i2-1]>b[i2]) {
					d=b[i2-1];
					b[i2-1]=b[i2];
					b[i2]=d;
				}
			}
		}		
	}				
}

int read_string(int a, unsigned char* b) {

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

int sread_array(int a, int* b, unsigned char* c) {
	
	int i1=0, i2=0; //INDEX1, INDEX2
	int i3=1, i4=0, i5=0; //MULTIPLAYER, NUMBER, FLAG

	while (c[i1]!='\0') {
		if (c[i1]>47 && c[i1]<58) {//DIGIT
			if (i5==0) {
				i4=c[i1]-48;//FIRST DIGIT
				i5=1;
			}	
			else
				i4=i4*10+c[i1]-48;//NEXT DIGIT
		}
		else {
			if (i5==1) {
				b[i2]=i3*i4;//NUMBER
				i2++;
				i3=1; i4=0; i5=0;//MULTIPLAYER, NUMBER, FLAG
			}	
			if (c[i1]=='-') {
				i3=-1; //MULTIPLAYER
				i5=1;
			}	
		}
		i1++;		
	}
	
	if (i5==1) {
		b[i2]=i3*i4;//NUMBER
		i2++;
	}
	
	return i2;
}	

void fprint_array(int a, int* b) {
	FILE *f2; 
	
	f2=fopen("output.txt", "w");

	for(int i=0;i<a;i++) {
		fprintf(f2, "%d ", b[i]);
	}	

	fclose(f2);
}	

int main()
{
	unsigned char a[SIZE+1];
	
	int b[SIZE/2], i1;
	
	read_string(SIZE+1, a);
	
	i1=sread_array(SIZE/2, b, a);
	
	asc_sort_array(i1, b);
	
	fprint_array(i1, b);

	return 0;
}
