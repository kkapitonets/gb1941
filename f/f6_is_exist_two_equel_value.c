#include <stdio.h>

#define SIZE 100

int is_exist(int a1, int a2, int* b, int c) {
	
	for(int i=a1;i<a2;i++) {
		if(b[i]==c) return 1;
	}
	
	return 0;
}	

 int is_exist_two_equel_value(int a, int* b){
	
	for(int i=0;i<a;i++) {
		if(is_exist(i+1, a, b, b[i]))
				return 1;
	}
	
	return 0;				
}

void read_array(int a, int* b) {
	
	for(int i=0;i<a;i++) {
		scanf("%d", &b[i]);
	}	
}	

int main()
{
	int a[SIZE];
	
	read_array(SIZE, a);
	
	printf("%s", is_exist_two_equel_value(SIZE, a)?"YES":"NO");
	
	return 0;
}


