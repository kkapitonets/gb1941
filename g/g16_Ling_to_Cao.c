#include <stdio.h>

#define SIZE 1400

int insert_string(unsigned char* s1, unsigned char* s2) {
	
	int i1=0;
	
	while (s1[i1]!='\0') {
		s2[i1]=s1[i1];
		i1++;
	}
	
	return i1;	
}

int is_letter(char a) {

	if (a>96 && a<123)//SMALL LETTER
		return 1;
	if (a>64 && a<91)//BIG LETTER
		return 1;
		
	return 0;	
}	

int fread_string(int a, unsigned char* b) {

	FILE *f1;
	
	unsigned char s1[]="Ling", s2[]="Cao", s3; 

	int i1=0, i2, i3=0;

	f1=fopen("input.txt", "r");
	
	do {
		i2=fscanf(f1, "%c", &b[i1]); 
		
		if (s1[i3]=='\0') {
			if(!is_letter(b[i1]) || is_letter(b[i1])) {//IT IS WRONG
				s3=b[i1]; 
				i1-=i3;
				i1+=insert_string(s2, &b[i1]);
				b[i1]=s3; 
				i3=0;
			}
			else
				i3=0;
		} 
		
		if (b[i1]==s1[i3])
			i3++;
		else {
			i3=0;
			if (b[i1]==s1[i3])//IT IS WRONG
				i3++;
		}	

	} while (b[i1++]!='\n' && i2==1 && i1<a);
	
	if (i2) i1--;
	
	b[i1]='\0';

	fclose(f1);
	
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
	
	fread_string(SIZE+1, a);
	
	fprint_string(a);

	return 0;
}
