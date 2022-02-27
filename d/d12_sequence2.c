#include <stdio.h>

void sequence2(int a, int b){

	for (int i=0;i<a;i++) {//1,5//2,4//3,2
	
		printf("%d ", a);//1//2 2
	
		if(!--b) break;//3 3
	
    }
    
    if (b) sequence2(a+1, b);//2,4//3,2
	
}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	if (i1>0) sequence2(1, i1);
	    
	return 0;
}
