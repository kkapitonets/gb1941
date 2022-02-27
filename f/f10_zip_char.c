#include <stdio.h>

int main()
{
	char s1=' ', s2;
	int i1=0;
	
	do {
		scanf("%c", &s2);
		
		if (s2!='.') {
			if (s1==' ')//FIRST SET
				s1=s2;
			
			if (s1==s2)//THE SAME SET
				i1++;//SET SIZE
			else {
					
				printf("%c%d", s1, i1);//LAST SET
				i1=1; //NEW SET
				s1=s2;
			}
		}
	} while (s2!='.');
	
	printf("%c%d", s1, i1);//LAST SET

	return 0;
}
