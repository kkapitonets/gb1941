#include <stdio.h>

int sum_digit(int a){
	
	int b;
	
	b=a%10;
	
	a=(a-b)/10;
	
	if(a>0) return b+=sum_digit(a);
	
	else return b;

}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	if(i1>0) printf("%d", sum_digit(i1));
	
	else printf("0");
	    
	return 0;
}
