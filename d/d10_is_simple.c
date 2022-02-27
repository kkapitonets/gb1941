#include <stdio.h>

int is_simple(int a, int b){
	
    if (a<2) return 0;//0, 1 IS NOT SIMPLE
    
    if (a<4 || b*b>a) return 1; //2, 3 IS SIMPLE
    
    else if (a%b++) return is_simple(a,b); //MAY BE SIMPLE
    
	else return 0; //IS NOT SIMPLE
}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	printf("%s", is_simple(i1, 2)?"YES":"NO");
	    
	return 0;
}
