#include <stdio.h>

/*
main()
{
	dec_to_bin(5)
	{
		5%2=1
		(5-1)/2=2
		dec_to_bin(2)
		{
			2%2=0
			(2-0)/2=1
			dec_to_bin(1)
			{
				1%2=1
				(1-1)/2=0
				else return 1
			}
			//dec_to_bin(1)=1
			return dec_to_bin(1)*10+0=1*10+0=10
		}
		//dec_to_bin(2)=10
		return dec_to_bin(2)*10+1=10*10+1=101
	}
    //dec_to_bin(5)=101
*/ 	

int sum_bin_digit(int a){

	int b;

	b=a%2;
	
	a=(a-b)/2;
	
	if(a>0) return b+=sum_bin_digit(a);
	
	else return b;
	
}

int main()
{
    int i1;
    
    scanf("%d", &i1);

	if(i1>0) printf("%d", sum_bin_digit(i1));
	
	else printf("0");
	    
	return 0;
}
