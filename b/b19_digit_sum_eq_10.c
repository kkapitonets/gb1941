#include <stdio.h>

int main()
{
    int i1, i2, i3=0;
    do{
      scanf("%d", &i1);
    } while (i1<0);
    
    while(i1!=0) {
      i2=i1%10;
      //printf("%d\n", i2);
      i3+=i2;
      i1=(i1-i2)/10;
    }
    
    printf("%s", i3==10?"YES":"NO");

    return 0;
}
