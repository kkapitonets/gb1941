#include <stdio.h>

int is_digit(char a1){

    return a1>47&&a1<58?1:0;

}

int digit_to_number(char a1){

    //printf("%d\n", a1-48);
    
    return a1-48;

}

int main()
{
    char a1;
    int i1=0;

    do {
    
		scanf("%c", &a1);
		
		if (is_digit(a1)) i1+=digit_to_number(a1);
		
	} while (a1!='.');
	    
	printf("%d", i1);
	    
	//printf("%d %d", '0', '9');
	
    return 0;
}
