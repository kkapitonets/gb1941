#include <stdio.h>

int main()
{
    int i1=1, i2=1;
    //printf("Введите положительное число меньше 100\n");
    do {
	  //if (i1<1 || i1>99) printf("Число должно быть положительное и меньше 100\n");	
      scanf("%d", &i1);
    } while (i1<1 || i1>99); 
    
    do{
      printf("%d %d %d\n", i2,i2*i2,i2*i2*i2);
    } while (i2++ < i1);
    
    return 0;
}
