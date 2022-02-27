#include <stdio.h>

int count_char(int i1){

	char a;

	scanf("%c", &a);
	
	if(a!='.') {
		i1=count_char(a=='a'?i1+1:i1);
	}
	
	return i1;	
	
}

int main()
{
	int i1=0;
	
	printf("%d", count_char(i1));
	    
	return 0;
}
