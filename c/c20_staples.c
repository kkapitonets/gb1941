#include <stdio.h>

int main()
{
    char a1;
    int i1=0, i2=0;

    do {
    
		scanf("%c", &a1);
		
		if (a1=='(') i1++;
		
		if (a1==')'&&!i1) i2++;
		
		if (a1==')') i1--;
		
	} while (a1!='.');
	    
	printf("%s", !i1&&!i2?"YES":"NO");
	    
	return 0;
}
