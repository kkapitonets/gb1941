#include <stdio.h>

int is_digit_in_order(int i1)
{
	int i2=0, i3=0, i4=0;
	
    i2=i1%10;
    i1=(i1-i2)/10;
    
    while(i1>0 && !i4){
      i3=i1%10;
      //printf("%d ", i2);
      i1=(i1-i3)/10;
      i4=i2<=i3;
      i2=i3;
	} 
	 
    return !i4?1:0;
}

int main()
{
    int i1;

    scanf("%d", &i1);
   
	printf("%s", is_digit_in_order(i1)?"YES":"NO");

    return 0;
}
