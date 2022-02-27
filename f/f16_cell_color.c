#include <stdio.h>

int char_to_digit(unsigned char s1) {
	
	if (s1>47 && s1<58)//DIGIT
		return s1-48;
	
	if (s1>64 && s1<91)//BIG LETTER
		return s1-64;

	if (s1>96 && s1<123)//SMALL LETTER
		return s1-96;
	
	return 0;
}	

int cell_color(unsigned char *s1) {
	
	int col, row;
	
	col=char_to_digit(s1[0]); 
	
	row=char_to_digit(s1[1]); 
	
	return ((col-1)*9+row)%2;//8+1 ADD A ROW TO START NEXT COLUMN WITH RIGHT COLOR
}	

int main()
{
	unsigned char s1[3];
	
	scanf("%s", s1);
	
	printf("%s", cell_color(s1)?"BLACK":"WHITE");
	
	return 0;
}
