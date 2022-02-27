#include <stdio.h>

int main()
{
    int i1, i2, i3;

    scanf("%d %d", &i1, &i2);
/*
r1=12 r2=56

r3=r1%r2=12

r1=r2 (56)

r2=r3 (12)

r3=r1%r2=8

r1=r2 (12)

r2=r3 (8)

r3=r1%r2=4

r1=r2 (8)

r2=r3 (4)

r3=r1%r2=0
*/    
    
    do {
		i3=i1%i2;
		i1=i2;
		i2=i3;
		//printf("%d %d\n", i1, i2);
	} while (i3);
    
    printf("%d", i1);
    
    return 0;
}
