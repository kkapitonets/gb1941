#include <stdio.h>

int cum(int a){

	if(a>1) return a+=cum(a-1);//sum 1 to a
	
	return a; //1
}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	if(i1>1) i1+=cum(i1-1);//sum 1 to i1
	    
	if(i1>0) printf("%d ", i1);//1
	
	else printf("0");//0
	    
	return 0;
}
