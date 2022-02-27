#include <stdio.h>

int main()
{
    int i1, i2, i3, i4, i5, i6;

    do {
		scanf("%d", &i1);
	} while (i1<10);
    
    i2=10;
    do {
	  i5=0; 
	  i6=1; 
	  i3=i2;	
      do {
		i4=i3%10;
		i3=(i3-i4)/10;
		i5+=i4;
		i6*=i4;
	  } while (i3);
    if(i5==i6) printf("%d ", i2);
    } while (i2++<i1);
    
    return 0;
}
