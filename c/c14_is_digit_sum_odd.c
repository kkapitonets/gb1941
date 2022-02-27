#include <stdio.h>

int digit_sum_is_odd(int i1)
{
	int i2, i3=0;
	
	while(i1!=0) {
      i2=i1%10;
      //printf("%d\n", i2);
      i3+=i2;
      i1=(i1-i2)/10;
    }
    
    return i3%2==0?1:0;
}

int main()
{
    int i1;

    scanf("%d", &i1);
   
	printf("%s", digit_sum_is_odd(i1)?"YES":"NO");

    return 0;
}
