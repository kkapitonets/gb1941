#include <stdio.h>

int main()
{
    int i1, i2=0, i3=0, i4=0;
    //printf("Введите целое положительное число\n");
    do {
	  //if (i1<0) printf("Число должно быть положительным\n");
      scanf("%d", &i1);
    } while (i1<0); 
    
    do {
      i2=i1%10;
      //printf("%d ", i2);
      i1=(i1-i2)/10;
      if(i2%2) i4++; else i3++;
 	} while(i1>0);
	 
    printf("%d %d", i3, i4);
    
    return 0;
}
