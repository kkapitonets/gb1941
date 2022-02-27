#include <stdio.h>

int func(int a) {
	
	int b;
	
	if(a<-2) b=4;
	else if(a<2) b=a*a;
	else b=a*a+4*a+5;
	
	return b;
}

int main()
{
    int i1, i2, i3;
    
    scanf("%d", &i1);
    
    i2=func(i1);
    //printf("%d\n", i2);
    
    while (i1!=0) {
		scanf("%d", &i1);
		i3=func(i1);
		//printf("%d\n", i3);
		if (i3>i2) i2=i3;
	}	
    
    printf("%d", i2);

    return 0;
}
