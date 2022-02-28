#include <stdint.h>
#include <stdio.h>

#include "st.h"

struct inst in_data[INSIZE];

struct outst out_data[OUTSIZE];

char month_s[OUTSIZE][MSIZE]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec","N/A"};

int hour(int dt) {
	
	return dt%24;	
}

int day(int dt) {

	return dt/24%31;	
}

int month(int dt) {

	return dt/24/31;
}

uint16_t to_date(int mn, int dy, int hh) {
	
	uint16_t dt=(mn*31+dy)*24+hh;
	
	return dt;
}

int is_month(char* sm) {

	int im;
	
	sscanf(sm, "%d", &im);
	
	if (im >0 && im <13) 
		return 1;

	return 0;
}

char* month_n(char* sm) {

	int im;
	
	sscanf(sm, "%d", &im);
	
	if (im >0 && im <13) 
		return month_s[im-1];

	return month_s[12];// N/A
}

void init_data(void) {

	for (int i=0;i<OUTSIZE;i++) {
		out_data[i].middle_t=0;
		out_data[i].min_t=0;
		out_data[i].max_t=0;
		out_data[i].count=0;
	}	
}

int read_data(char* fn) {
	
	FILE* f;
	
	if((f=fopen(fn, "r"))) {

		//READ FILE LINE BY LINE

		fclose(f);

		return 1;
	}
	else {
		printf("\nFile '%s' not found\n", fn);
		return -1;
	}
	
	return -1;	
}

void operate_data(void ) {
	
	//OPERATE LINE BY LINE
	
}

