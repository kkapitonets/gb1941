#include <stdio.h>

#include "st.h"

extern int lf, ui, qt;

int main(int argc, char *argv[]) {

	init_sun_time();
	
	init_statistic();

	if(argc-1 && operate_arg(argc-1, &argv[1])==1 && (lf || ui)) {//ENOUGH PARAMETERS, RIGHT PARAMETERS, FILE LOAD
		
		if (!ui) {//FREE
			qt=1;
		}
		
		operate();
	}
	else {		
		if (!lf) {
			printf("No file load parameter\n");
		}
		printf("\nts -h | -f [DISK:][PATH]FILENAME.csv [-i] [-t MN|MD|SR|SS | -p BEGIN END] [-m MONTH]\n\n");
		printf("-h\t help\n");
		printf("-f [DISK:][PATH]FILENAME.csv\n\t file name\n");
		printf("-i\t start user interface\n");
		printf("-t MN|MD|SR|SS\n\t type of period:\n");
		printf("\t MN\t Midnight (from sunset to sunrise)\n");
		printf("\t MD\t Midday (from sunrise to sunset)\n");
		printf("\t SR\t Sunrise (from hour before sunrise two hours after sunrise)\n");
		printf("\t SS\t Sunset (from two hour befor sunset hour after sunset)\nn");
		printf("-p BEGIN END\n\t specific period (from BEGIN hour to END hour)\n");
		printf("-m MONTH\n\t month statistic (other way year statistic)\n");
		printf("\t MONTH\t month number\n");
		printf("for example\n\n");
		printf("ts -f temperature_big.csv -m 2\n\n");
		printf("or\n\n");
		printf("ts -f temperature_big.csv\n");
	}
		
	return 0;
}	
