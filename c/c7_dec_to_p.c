#include <stdio.h>

int d_to_p(int a, int b) {

	int c=0, d=1;
	
	do{
		c+=a%b*d;
		//printf("%d\n", c);
		a/=b;
		d*=10;
    } while(a>0);
    	
	return c;
}

int main()
{
    int i1, i2;
    
    scanf("%d %d", &i1,&i2);
    
    printf("%d", d_to_p(i1, i2));

    return 0;
}
