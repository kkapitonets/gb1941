#include <stdio.h>

int is_happy_number(int i1){

	int i2, i3, i4;

	i3=0; 
	i4=1;
	
	do {
		i2=i1%10;
		i1=(i1-i2)/10;
		i3+=i2;
		i4*=i2;
	  } while (i1);

    return i3==i4?1:0;
}

int main()
{
    int i1;

    scanf("%d", &i1);
   
	printf("%s", is_happy_number(i1)?"YES":"NO");
/*	
	i1=100;
	do {
		if(is_happy_number(i1)) printf("\n%d", i1);
	} while (++i1<10001);
*/	
    return 0;
}
