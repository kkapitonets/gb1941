#include <stdint.h>
#include <stdio.h>

#include "st.h"

struct inst in_data[INSIZE];

int index[INSIZE];

int last=-1;

struct outst out_data[OUTSIZE];

float sr[365];
float ss[365];

char month_s[OUTSIZE][MSIZE]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec","N/A"};

int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};

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

void init_data(void) {

	for (int i=0;i<OUTSIZE;i++) {
		out_data[i].middle_t=0;
		out_data[i].min_t=0;
		out_data[i].max_t=0;
		out_data[i].count=0;
	}	
}

int read_data(char* fn) {
	
	FILE *f, *h;
		
	int i1=0, d[6], i2, i3, i4, i5;
	
	char s[10];
	
	set_sun_time();
	
	h=fopen("ts.log", "w");

	if((f=fopen(fn, "r"))) {

		//READ FILE LINE BY LINE
		do {
		
			i5=1;
			
			for (int i=0;i<6;i++) {
				
				i2=-1;
				
				//READ LINE CHAR BY CHAR
				do {
					i2++;
					i3=fscanf(f, "%c", &s[i2]);
				} while (i3!=-1 && s[i2]!='\n' && s[i2]!=';');//END OF FILE, END OF LINE, END OF PARAMETER
				
				s[i2]='\0';
				
				d[i]=-1;
				
				//READ PARAMETER BY PAREMETER
				i4=sscanf(s, "%d;", &d[i]);//YEAR, MM, DD, HH, MI, T //printf("%d '%s' %d\n", i4, s, d[i]);

				if (i4!=1) {
					fprintf(h, "Error in line %d no parameter %d\n", i1, i+1);
				}	
				else if (i==0 && d[0]!= 2021) {
					fprintf(h, "Error in line %d year %d\n", i1, d[0]);
					i5=0;
				}	
				else if (i==1 && (d[1]<1||d[1]>12) ) {
					fprintf(h, "Error in line %d month %d\n", i1, d[1]);
					i5=0;
				}	
				else if (i==2 && (d[2]<1||d[2]>m[d[1]-1]) ) {//BY DAY IN MONTH
					fprintf(h, "Error in line %d day %d for month %d\n", i1, d[2], d[1]);
					i5=0;
				}	
				else if (i==3 && (d[3]<0||d[3]>23) ) {
					fprintf(h, "Error in line %d hour %d\n", i1, d[3]);
					i5=0;
				}	
				else if (i==4 && (d[4]<0||d[4]>59) ) {
					fprintf(h, "Error in line %d minute %d\n", i1, d[4]);
					i5=0;
				}	
				else if (i==5 && (d[5]<-99||d[5]>99) ) {
					fprintf(h, "Error in line %d temperature %d\n", i1, d[5]);
					i5=0;
				}	
					
				if (i3==-1)//END OF FILE
				break;	
			}
			
			if (i5) add_data(d);

			if (i3==-1)
				printf("Total %d records, picked %d records\n", i1, last+1);

		} while(i1++<600000 && i3!=-1);//TEST, END OF FILE
		
		fclose(f);
		
		fclose(h);

		return 1;
	}
	else {
		printf("\nFile '%s' not found\n", fn);
		return -1;
	}
	
	return -1;	
}

void add_data(int* d) {
	
	int dt = to_date(d[1], d[2], d[3]), curr;
	
	if ((curr = find_data(dt)) == -1) {
		last++;
		in_data[last].date = dt;
		in_data[last].t = d[5];
		in_data[last].count = 1;

		index[last] = last;

		sort_data();
	}
	else {
	
		in_data[curr].t = (d[5] + in_data[curr].t*in_data[curr].count)/(in_data[curr].count+1);//MIDDLE HOUR TEMPERATURE
		in_data[curr].count++;
	}
}

int find_data(int dt) {

	int curr = last - 1;
	
	if (last == -1 || in_data[index[last]].date == dt) {

		return last;
	}
	else {
		while (curr > -1 && in_data[index[curr]].date > dt) {
			curr--;
		}
		
		if (in_data[index[curr]].date == dt)
			return index[curr];
		else
			return -1;
	}	
}

void sort_data(void) {
	
	int curr = last - 1, i1;
	
	while (curr > -1 && in_data[index[curr]].date > in_data[index[curr+1]].date) {//MOVE LESS TO BEGIN
		i1 = index[curr];
		index[curr] = last;
		index[curr+1] = i1;
		curr--;
	}	
}

void operate_data(int st, int h1, int h2) {
	
	char st_name[6][16]={"Middle Day","Middle Midnight","Middle Sunrise","Middle Sunset","Middle Midday","Middle by time"};
	
	int mn, dy, hr, t, dt;
	
	//OPERATE LINE BY LINE
	
	init_data();

	printf("%s Temperature\n", st_name[st]);
	
	for (int i=0;i<last+1;i++) {
		
		mn = month(in_data[index[i]].date);
		dy = day(in_data[index[i]].date);
		hr = hour(in_data[index[i]].date);
		t  = in_data[index[i]].t;
		
		dt = dm(mn, dy)-1;
		
		if (st == 0) {//DAY
			set_statistic(&out_data[mn-1],t);
		}
		else if (st == 1) {//MIDNIGHT	
			if (hr>ss[dt] || hr<sr[dt] )
				set_statistic(&out_data[mn-1],t);
		}
		else if (st == 2) {//SUNRISE	
			if (hr>sr[dt]-1 && hr<sr[dt]+2 )
				set_statistic(&out_data[mn-1],t);
		}
		else if (st == 3) {//SUNSET	
			if (hr>ss[dt]-2 && hr<ss[dt]+1 )
				set_statistic(&out_data[mn-1],t);
		}
		else if (st == 4) {//MIDDAY	
			if (hr>sr[dt] && hr<ss[dt] )
				set_statistic(&out_data[mn-1],t);
		}
		else if (st == 5) {//BY TIME
			if (hr>h1-1 && hr<h2+1 )
				set_statistic(&out_data[mn-1],t);
		}		
	}
}

void set_sun_time(void) {
	
	float d=0.022;
	
	sr[0]=7.78;//SUNSIZE JANUARY 1
	
	ss[0]=16.22;//SUNSET JANUARY 1
	
	for (int i=1;i<365;i++) {
			
		if (i<174 || i>354) {
			sr[i]=sr[i-1]-d;
			ss[i]=ss[i-1]+d;
		}
		else {	
			sr[i]=sr[i-1]+d;
			ss[i]=ss[i-1]-d;
		}
	}
}	

int md(int dt, int dm) {

	for (int i=0;i<11;i++) {
		if (dt>m[i]) 
			dt-=m[i];
		else
			return dm?i+1:dt;
	}
	
	return dm?12:dt;		
}

int dm(int mn, int dy) {

	int dt=0;
	
	for (int i=0;i<mn;i++) {

		dt+=m[i];
	}
	
	return dt+dy;		
}

		
void set_statistic(struct outst* st, int t) {
	
	if (st->count) {
		if (st->max_t<t)
			st->max_t=t;
		if (st->min_t>t)
			st->min_t=t;	
	}
	else {
		st->max_t=t;
		st->min_t=t;	
	}		
	st->middle_t = (st->middle_t*st->count+t)/(st->count+1);
	st->count++;
}
