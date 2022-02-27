#include <stdio.h>

char s_to_l(char a) {

	int i1;
	
  	i1=a>96&&a<123;
  	
	return i1?a-32:a;
}

int main()
{
    char s1;
    
	do {
		scanf("%c", &s1);
		if(s1!='.') {
			printf("%c", s_to_l(s1));
		} 
	} while (s1!='.');
	
    return 0;
}
