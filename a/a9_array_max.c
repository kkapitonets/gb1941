#include <stdio.h>

int main()
{
    int i[5],j;
    scanf("%d %d %d %d %d", &i[0],&i[1],&i[2],&i[3],&i[4]);
    j=i[0];
    for(int k=1; k<5; k++){
        if(i[k]>j) j=i[k];
    }
    printf("%d", j);
    return 0;
}