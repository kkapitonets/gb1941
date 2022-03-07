#include <stdio.h>
#include <stdint.h>

#include "st.h"

extern struct outst out_data[OUTSIZE];

extern char month_s[OUTSIZE][MSIZE];

int main(int argc, char *argv[]) {
	
	if (argc==3 && argv[1][1]=='f') {
		if(read_data(argv[2])!=-1) {
			for (int i=0;i<6;i++) {//TEST OPERATION

				operate_data(i, 10, 14);
				printf("Month\tMiddle\tMinimum\tMaximum\n");
				for (int i=0;i<12;i++) {
					printf("%s\t%.1f\t%.1f\t%.1f\n", month_s[i], out_data[i].middle_t, out_data[i].min_t, out_data[i].max_t);
				}
				printf("Year\t%.1f\t%.1f\t%.1f\n", out_data[12].middle_t, out_data[12].min_t, out_data[12].max_t);
			}	
		}
	}
	else if (argc==5 && argv[1][1]=='f' && argv[3][1]=='m' && is_month(argv[4])) {
		if(read_data(argv[2])!=-1) {
			for (int i=0;i<6;i++) {//TEST OPERATION

				operate_data(i, 15, 20);
				{
					int im;
					sscanf(argv[4], "%d", &im);
					printf("Month\tMiddle\tMinimum\tMaximum\n");
					printf("%s\t%.1f\t%.1f\t%.1f\n", month_s[im-1], out_data[im-1].middle_t, out_data[im-1].min_t, out_data[im-1].max_t);
				}
			}
		}
	}
	else {		
		printf("\nts -h | -f [disk:][path]filename.csv [-m month]\n\n");
		printf("-h\t help\n");
		printf("-f [disk:][path]filename.csv\n\t file name\n");
		printf("-m month\n\t month statistic\n\t other way year statistic \n\n");
		printf("for example\n\n");
		printf("ts -f temperature_big.csv -m 2\n\n");
		printf("or\n\n");
		printf("ts -f temperature_big.csv\n");
	}

	return 0;
}	
