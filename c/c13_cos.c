#include <stdio.h>
#include <math.h>

const float PI=3.1415926535, E=0.001;

float _cos(float x)
{
    float v=1, m=1;
    int f=1;
    
    do {
		
		m*=-1.0*x*x/f/2/(f*2-1);
		//printf("%f %f\n", v, m);
		
		f++;
		
		v+=m;
		
	} while (fabs(m)>E);	

    return v;
}

int main()
{
    float x1;
    
    scanf("%f",&x1);
    
    printf("%.3f", _cos(x1*PI/180.0));
    
    return 0;
    
}    
