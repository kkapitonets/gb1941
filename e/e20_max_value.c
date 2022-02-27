#include <stdio.h>

int count_digit(int a) {

	int i1=0;
		
	do {
	
		a=a/10;
		i1++;
	} while (a>0);
	
	return i1;	
}	

int shift_digit(int a, int* b) {
	
	int i1, i2, i3=*b, i4=1;
	
	//printf("%d %d/", *b, a);

	for (int i=0;i<a;i++) {//SKIP a DIGIT
	
		i3=i3/10;
		i4*=10; //PREPARE MULTIPLYER
	}
	
	i2=i3%10;//RIGHT DIGIT
	i1=(i3-i2)%100/10;//LEGT DIGIT

	//printf("%d %d %d\n", i1, i2, i4);
	
	if (i1<i2) {//IF LEFT DIGIT LESS
	
		*b+=((i2-i1)*10+i1-i2)*i4; //SWAP LEFT AND RIGHT DIGIT

		//printf("%d\n", *b);
		return 1;
	}
	else return 0;	
}

int main()
{
	int i1, i2;
	
	scanf("%d", &i1);
	
	if (i1>0) {
		i2=count_digit(i1);
		//printf("%d\n", i2);	

 		for(int i3=i2-1;i3>0;i3--) {
			if (shift_digit(i3-1, &i1)) {
				for(int i4=i3+1;i4<i2;i4++) {
					if(!shift_digit(i4-1, &i1))
						break;
				}	
			} 	
		//printf("RIGHT %d\n", i3);	
		}
		printf("%d", i1);	
	}
	else printf("0");
	
	return 0;
}
