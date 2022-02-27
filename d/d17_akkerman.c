#include <stdio.h>

int akkerman(int m, int n){
	
	int ret1, ret2;
	
	if (!m) {//m=0; 

		//printf("1:RETURN %d+1=%d\n", n, n+1); 

		return n+1;

	}

	if (!n) {//m>0, n=0;
		
		//printf("2:PUT (%d-1=%d SET 1)\n", m, m-1);
		
		ret1=akkerman(m-1, 1);
		
		//printf("2:RETURN (%d-1=%d SET 1)=%d\n", m, m-1, ret1);
		
		return ret1;
	}
	
	//printf("3:PUT (%d %d-1=%d)\n", m, n, n-1);
	
	ret1=akkerman(m, n-1);//m>0, n>0;
	
	//printf("3:RETURN (%d %d-1=%d)=%d\n", m, n, n-1, ret1);
	
	//printf("4:PUT (%d-1=%d %d)\n", m, m-1, ret1);
	
	ret2=akkerman(m-1, ret1); 
	
	//printf("4:RETURN (%d-1=%d %d)=%d\n", m, m-1, ret1, ret2);
	
	return ret2; 
	
}

int main()
{
	int i1, i2;
	
	scanf("%d %d", &i1, &i2);
	
	printf("%d", akkerman(i1, i2)); 
	    
	return 0;
}
