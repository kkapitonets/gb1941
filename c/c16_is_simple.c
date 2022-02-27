#include <stdio.h>

int is_simple(int a){

	if (a<2) return 0;
	
	if (a<4) return 1;
	
  	for(int i=2;i*i<=a;i++){
		if(a%i==0) return 0;
	}	
    
    return 1;
}

int main()
{
    int i1;

    scanf("%d", &i1);
   
	printf("%s", is_simple(i1)?"YES":"NO");

    return 0;
}
