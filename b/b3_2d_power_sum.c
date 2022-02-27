#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i1=1, i2=1, i3, i4=0;
    //printf("Введите два числа в порядке возрастания по модулю не больше 100\n");
    do {
	  //if (i2 < i1) printf("Числа должны быть по порядку\n");
	  //if (abs(i1)>100 || abs(i2)>100) printf("Числа должны быть по модулю не больше 100\n");	
      scanf("%d %d", &i1,&i2);
    } while (i2 < i1 || abs(i1)>100 || abs(i2)>100); 
    
    i3=i1;
    do {
		i4+=i3*i3;
		//printf("%d ", i4);
    } while(i3++<i2);
    
    printf("%d", i4);

    return 0;
}
