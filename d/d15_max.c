#include <stdio.h>

int _max(int a){
	
	int b;
	
	scanf("%d", &b);
	
	if (b) {//IS VALUE
		
		if (a) a=_max(a<b?b:a); //IS NEXT VALUE
		
		else a=_max(b);//IS FIRST VALUE
	}
	
	return a; //RESULT	
}

int main()
{
	int a=0;
	
	if ((a=_max(a))) printf("%d", a); //NO VALUE, NO PRINT
	    
	return 0;
}
