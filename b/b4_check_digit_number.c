#include <stdio.h>

int main()
{
    int i1=1, i2=0;
    //printf("?????? ??? ????????? ??\n");
    do {
	  //if (i1<0) printf("??? ?????? ???? ?????????\n");
      scanf("%d", &i1);
    } while (i1<0); 
    
    i2 = i1>99 && i1<1000; 
    printf("%s", i2 ? "YES":"NO");

    return 0;
}
