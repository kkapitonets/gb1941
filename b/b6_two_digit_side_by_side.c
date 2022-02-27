#include <stdio.h>

int main()
{
    int i1, i2=0, i3=0, i4=0;
    //printf("Введите целое положительное число\n");
    do {
	  //if (i1<0) printf("Число должно быть положительным\n");
      scanf("%d", &i1);
    } while (i1<0); 
    
    i2=i1%10;
    i1=(i1-i2)/10;
    
    while(i1>0 && !i4){
      i3=i1%10;
      i4=i2==i3;
      //printf("%d %d %d\n", i2, i3, i4);
      i1=(i1-i3)/10;
      i2=i3;
	}

    printf("%s",i4 ? "YES":"NO");
    
    return 0;
}
