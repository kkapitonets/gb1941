#include <stdio.h>

int main()
{
    int i1, i2=0;
    do {
      scanf("%d", &i1);
      if(i1 && !(i1%2)) i2++;
      //printf("%d %d\n", i1, !(i1%2));
    } while (i1); 
    
    printf("%d", i2);
    
    return 0;
}
