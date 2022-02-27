#include <stdio.h>

double power(int d1, int i1){

	if(--i1) {
		return power(d1, i1)*d1;
	}
	
	return (double) d1;	
	
}

int main()
{
	int d1;
	int i1;
	
	scanf("%d %d", &d1, &i1);
	
	if (i1>0) printf("%.0lf", power(d1, i1));
	
	else printf("1");
	    
	return 0;
}
