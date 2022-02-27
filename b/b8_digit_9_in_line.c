#include <stdio.h>

int main()
{
    int i1, i2=0, i3=0, i4[10]={0,0,0,0,0,0,0,0,0,0};
    //printf("Введите целое положительное число\n");
    do {
	  //if (i1<0) printf("Число должно быть положительным\n");
      scanf("%d", &i1);
    } while (i1<0); 
    
     do{
      i2=i1%10;
      //printf("%d ", i2);
      i1=(i1-i2)/10;
      ++i4[i2];
	} while(i1>0);
	 
    i3=i4[9]==1;
    printf("%s", i3 ? "YES":"NO");
    
    return 0;
}
