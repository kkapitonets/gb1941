#include <stdio.h>

int sum(int a) {

	int i, b=0;
	
	
	for(i=0;i<a;i++){
		b+=i;
    }	
	
	return b+a;
}

int main()
{
    int i1;
    
    scanf("%d", &i1);
    
    printf("%d", sum(i1));

    return 0;
}
