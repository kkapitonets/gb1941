#include <stdio.h>

void back_sequence(int a){

	if(a>0) {
		printf("%d ", a);  

		back_sequence(a-1);
	}
}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	if(i1>0) back_sequence(i1);
	    
	return 0;
}
