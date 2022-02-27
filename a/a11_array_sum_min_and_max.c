#include <stdio.h>

int main()
{
    int i[5],j1,j2;
    scanf("%d %d %d %d %d", &i[0],&i[1],&i[2],&i[3],&i[4]);
    j1=i[0];
    j2=i[0];
    for(int k=1; k<5; k++){
        if(i[k]<j1) j1=i[k];
        if(i[k]>j2) j2=i[k];
    }
    printf("%d", j1+j2);
    return 0;
}