#include <stdio.h>

int simple(int a){

	if (a<4) return a;
	
  	for(int i=2;i*i<=a;i++){
		if(a%i==0)return i;
	}	
    
    return a;
}

void print_simple(int a) {

  	int b;
  	
  	do {
		b=simple(a);
		if (b>1) printf("%d ", b);
		a/=b;
	} while(a>1);
  	
}

int main()
{
    int i1;
    
	scanf("%d", &i1);
	
	print_simple(i1);
	
    return 0;
}
