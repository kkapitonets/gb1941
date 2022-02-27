#include <stdio.h>

int main()
{
  char s1;
  int i1;
  
  do {
    scanf("%c", &s1);
    if(s1!='.') {
      i1= s1>64&&s1<91;
      printf("%c", i1 ? s1+32:s1);
    } 
  } while (s1!='.');
  
  return 0;
}
