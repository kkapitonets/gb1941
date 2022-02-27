#include <stdio.h>

int main()
{
    int i1, i2, i3, i4, i5;

    do {
		scanf("%d", &i1);
	} while (i1<0);
    
    i2=1;
    i3=1;
    for (i5=0;i5<i1;i5++) {
	  if(i5<2) printf ("1 ");
	  else {
		i4=i2+i3;
		i2=i3;
		i3=i4;
		printf("%d ", i4);  
		}	
	  }
    
    return 0;
}
