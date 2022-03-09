#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "st.h"

indt *hour_data=NULL;//HOUR STATISTIC, hour_data=malloc(INSIZE*sizeof(indt));

int index[INSIZE];//HOUR STATISTIC INDEX

int last=-1;//HOUR STATISTIC POINTER

struct outst month_data[12];//MONTH STATISTIC

struct outst year_data;//YEAR STATISTIC

float sr[365];//SUNRISE TIME
float ss[365];//SANSET TIME

char month_name[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};//MONTH NAME

int ml[12]={31,28,31,30,31,30,31,31,30,31,30,31};//MONTH LENGHT

char *fn;//FILE NAME

int ui=0, pt=0, h1=0, h2=23, im=0, lf=0, qt=0, yr=0, hl=0, pd=0;//USER INTERFACE, PERIOD TYPE, HOUR FROM, HOUR TO, MONTH NUMBER, LOAD FILE, QUIT, YEAR STATISTIC (USER INTERFACE), PRINT HOUR DATA

char pt_name[6][16]={"Middle Day","Middle Midnight","Middle Midday","Middle Sunrise","Middle Sunset","Middle by time"};

//-----
int to_hour(int dt) {//FROM DATE TO HOUR
	
	return dt%24;	
}

//-----
int to_day(int dt) {//FROM DATE TO DAY

	return dt/24%31;	
}

//-----
int to_month(int dt) {//FROM DATE TO MONTH

	return dt/24/31;
}

//-----
uint16_t to_date(int mn, int dy, int hh) {//FROM MONTH, DAY, HOUR TO DATE
	
	uint16_t dt=(mn*31+dy)*24+hh;
	
	return dt;
}

//-----
int is_month(char* sm) {//CHECK MONTH NUMBER 

	int im;
	
	sscanf(sm, "%d", &im);
	
	if (im >0 && im <13) 
		return 1;

	return 0;
}

//-----
void init_statistic(void) {//INIT DATA
	
	pt=0;	//PERIOD TYPE
	h1=0;	//HOUR FROM  
	h2=23;	//HOUR TO
	im=0;	//MONTH NUMBER
	lf=0;	//LOAD FILE
	yr=0;	//YEAR STATICTIC (USER INTERFACE)
	hl=0;	//HELP (USER INTERFACE)
	pd=0;	//PRINT HOUR DATA (USER INTERFACE)

	for (int i=0;i<12;i++) {
		month_data[i].middle_t=0;
		month_data[i].min_t=0;
		month_data[i].max_t=0;
		month_data[i].count=0;
	}
	
	year_data.middle_t=0;
	year_data.min_t=0;
	year_data.max_t=0;
	year_data.count=0;
}

//-----
int read_data() {//READ DATA FILE
	
	FILE *f, *h;
		
	int i1=0, d[6], i2, i3, i4, i5;
	
	char pr[10];
	
	h=fopen("ts.log", "w");//LOG FILE
	
	last=-1;

	if((f=fopen(fn, "r"))) {//DATA FILE
		
		hour_data=malloc(INSIZE*sizeof(indt));

		//READ FILE LINE BY LINE
		do {
		
			i5=1;
			
			for (int i=0;i<6;i++) {
				
				i2=-1;
				
				//READ LINE CHAR BY CHAR
				do {
					i2++;
					i3=fscanf(f, "%c", &pr[i2]);
				} while (i3!=-1 && pr[i2]!='\n' && pr[i2]!=';');//END OF FILE, END OF LINE, END OF PARAMETER
				
				pr[i2]='\0';
				
				d[i]=-1;
				
				//READ PARAMETER BY PAREMETER
				i4=sscanf(pr, "%d;", &d[i]);//YEAR, MM, DD, HH, MI, T //printf("%d '%s' %d\n", i4, s, d[i]);

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
				else if (i==2 && (d[2]<1||d[2]>ml[d[1]-1]) ) {//BY DAY IN MONTH
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
				printf("Total %d records by minutes, picked %d records by hours\n", i1, last+1);

		} while(i1++<TESTSIZE && i3!=-1);//TEST, END OF FILE
		
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

//-----
void add_data(int* d) {//ADD HOUR DATA
	
	int dt = to_date(d[1], d[2], d[3]), curr;
	
	struct inst *hd;
	
	if ((curr = find_data(dt)) == -1) {
		last++;
		hour_data[last].date = dt;
		hour_data[last].middle_t = d[5];
		hour_data[last].count = 1;

		index[last] = last;

		sort_data();
	}
	else {
		hd=&hour_data[index[curr]];
		
		hd->middle_t = (d[5] + hd->middle_t*hd->count)/(hd->count+1);//MIDDLE HOUR TEMPERATURE
		hd->count++;
	}
}

//-----
int find_data(int dt) {//SEARCH HOUR DATA BY INDEX

	int curr = last - 1;
	
	if (last == -1 || hour_data[index[last]].date == dt) {

		return last;
	}
	else {
		while (curr > -1 && hour_data[index[curr]].date > dt) {
			curr--;
		}
		
		if (hour_data[index[curr]].date == dt)
			return curr;
		else
			return -1;
	}	
}

//-----
void sort_data(void) {//REBUILD HOUR DATA INDEX
	
	int curr = last - 1, i1;
	
	while (curr > -1 && hour_data[index[curr]].date > hour_data[index[curr+1]].date) {//MOVE LESS TO BEGIN
		i1 = index[curr];
		index[curr] = last;
		index[curr+1] = i1;
		curr--;
	}	
}

//-----
void operate_statistic(void) {//OPERATE AND PRINT DATA
	
	int mn, dy, hr, dt;
	
	float t;
	
	//OPERATE LINE BY LINE
	
	if (last ==-1) {
		printf("No data\n");
	}
	else {
		printf("\n%s Temperature\n", pt_name[pt]);
		
		for (int i=0;i<last+1;i++) {
			
			mn = to_month(hour_data[index[i]].date);
			dy = to_day(hour_data[index[i]].date);
			hr = to_hour(hour_data[index[i]].date);
			t  = hour_data[index[i]].middle_t;
			
			dt = dm(mn, dy)-1;
			
			if (pt == 0) {//DAY
				add_statistic(&month_data[mn-1],t);
				add_statistic(&year_data,t);
			}
			else if (pt == 1) {//MIDNIGHT	
				if (hr>ss[dt] || hr<sr[dt]) {
					add_statistic(&month_data[mn-1],t);
					add_statistic(&year_data,t);
				}	
			}
			else if (pt == 2) {//SUNRISE	
				if (hr>sr[dt]-2 && hr<sr[dt]+3) {
					add_statistic(&month_data[mn-1],t);
					add_statistic(&year_data,t);
				}	
			}
			else if (pt == 3) {//SUNSET	
				if (hr>ss[dt]-3 && hr<ss[dt]+2) {
					add_statistic(&month_data[mn-1],t);
					add_statistic(&year_data,t);
				}	
			}
			else if (pt == 4) {//MIDDAY	
				if (hr>sr[dt]-1 && hr<ss[dt]+1) {
					add_statistic(&month_data[mn-1],t);
					add_statistic(&year_data,t);
				}	
			}
			else if (pt == 5) {//BY TIME
				if (hr>h1-1 && hr<h2+1) {
					add_statistic(&month_data[mn-1],t);
					add_statistic(&year_data,t);
				}	
			}		
		}
		
		printf("Month\tMiddle\tMinimum\tMaximum\n");
		if (im) {
			printf("%s\t%6.2f\t%6.2f\t%6.2f\n", month_name[im-1], month_data[im-1].middle_t, month_data[im-1].min_t, month_data[im-1].max_t);
		}	
		else {
			for (int i=0;i<12;i++) {
				printf("%s\t%6.2f\t%6.2f\t%6.2f\n", month_name[i], month_data[i].middle_t, month_data[i].min_t, month_data[i].max_t);
			}
			printf("Year\t%6.2f\t%6.2f\t%6.2f\n", year_data.middle_t, year_data.min_t, year_data.max_t);
		}	
	}
}

//-----
void init_sun_time(void) {//SET SUNRISE AND SUNSET TIME
	
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

//-----
int md(int dt, int dm) {//DAY OF YEAR TO MONTH OR DAY

	for (int i=0;i<11;i++) {
		if (dt>ml[i]) 
			dt-=ml[i];
		else
			return dm?i+1:dt;
	}
	
	return dm?12:dt;		
}

//-----
int dm(int mn, int dy) {//MONTH, DAY TO DAY OF YEAR

	int dt=0;
	
	for (int i=0;i<mn;i++) {

		dt+=ml[i];
	}
	
	return dt+dy;		
}
		
//-----
void add_statistic(struct outst* st, float t) {//SAVE DATA
	
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
	st->middle_t = (t+st->middle_t*st->count)/(st->count+1);
	st->count++;
}

//-----
int operate_arg(int argc, char *argv[]) {
	
	int i1;

	if (argv[0][1]=='f') {//FILE NAME
		if (argc>1) {
			fn=argv[1];
			lf=1;
			if (argc-2) {
				return operate_arg(argc-2, &argv[2]);
			}	
			else {
				return 1;
			}	
		}
		else {
			printf("No file name\n");	
			return -1;//NO FILE NAME
		}		
	}
	else if (argv[0][1]=='i'&& ui==0) {//USER INTERFACE, NO RECURCE
		ui=1;
		if (argc-1) {
			return operate_arg(argc-1, &argv[1]);
		}
		else {
			return 1;
		}		
	}
	else if (argv[0][1]=='m') {//MONTH CTATISTIC
		if (argc>1) {
			i1=sscanf(argv[1], "%d", &im);
			if (i1==1 && im>0 &&im<13) {
				if (argc-2) {
					return operate_arg(argc-2, &argv[2]);
				}
				else {
					return 1;
				}	
			}
			else {
				printf("Number is not month\n");
				return -1;//NUMBER IS NOT MONTH
			}	
		}
		else {
			printf("No month number\n");
			return -1;//NO MONTH NUMBER	
		}	
	}
	else if (argv[0][1]=='d') {//PRINT HOUR DATA BY MONTH
		if (argc>1) {
			i1=sscanf(argv[1], "%d", &im);
			if (i1==1 && im>0 &&im<13) {
				pd=1;
				if (argc-2) {
					return operate_arg(argc-2, &argv[2]);
				}
				else {
					return 1;
				}	
			}
			else {
				printf("Number is not month\n");
				return -1;//NUMBER IS NOT MONTH
			}	
		}
		else {
			printf("No month number\n");
			return -1;//NO MONTH NUMBER	
		}	
	}
	else if (argv[0][1]=='t') {//PERIOD TYPE
		if (argc>1) {
					
			if (strcmp(argv[1],"MN")==0) {//MIDNIGHT
				pt=1;
			}
			else if (strcmp(argv[1],"MD")==0) {//MIDDAY
				pt=2;
			}
			else if (strcmp(argv[1],"SR")==0) {//SUNRISE
				pt=3;
			}
			else if (strcmp(argv[1],"SS")==0) {//SUNSET
				pt=4;
			}
			else {
				printf("Not vaid period type\n");
				return -1;//NOT VALID PERIOD TYPE
			}	
			if (argc-2) {
				return operate_arg(argc-2, &argv[2]);
			}	
			else {
				return 1;
			}	
		}
		else {
			printf("No period type\n");
			return -1;//NO PERIOD TYPE
		}		
	}		
	else if (argv[0][1]=='p') {//SPECIFIC PERIOD
		if (argc>2) {
			int i1;
			i1=sscanf(argv[1], "%d", &h1);
			i1+=sscanf(argv[2], "%d", &h2);
			if (i1==2 && h1>0 && h1<13 && h2>0 && h2<13) {
				if(h1>h2) {
					i1=h2;
					h2=h1;
					h1=i1;
				}
				pt=5;	
				if (argc-3) {
					return operate_arg(argc-3, &argv[3]);
				}
				else {
					return 1;
				}	
			}
			else {
				printf("Wrong period limits\n");
				return -1;//WRONG PERIOD LIMITS
			}	 
		}
		else {
			printf("No period limits\n");
			return -1;//NO PERIOD LIMITS
		}		
	}
	else if (argv[0][1]=='y') {
		yr=1;
		return 1;//YEAR STATICTIC (USER INTERFACE)
	}
	else if (argv[0][1]=='q') {
		qt=1;
		return 1;//QUIT
	}
	else if (argv[0][1]=='h') {
		hl=1;
		return -1;//HELP
	}

	printf("Not valid parameter\n");	
	return -1;//NOT VALID PARAMETER
}

//-----
void operate(void) {//OPERATE DATA
	
	int i1;
	
	if (lf) {
		i1=read_data();
	}
	
	if (!lf || (lf && i1>0)) {
		if (pd) {
			print_statistic();
		}	
		else {
			operate_statistic();
		}	
	}	
	
	if (ui) {
		user_interface();
	}
	
	if (qt) {
		free(hour_data);
	}	
	
}

//-----
void user_interface(void) {//USER INTERFACE
	
	int i1, stc;
	char st[STSIZE];
	char *stv[STVSIZE];
	
	ui=0; //NO RECURCE
	
	while (1) {
		printf("ts>");
		
		i1=-1;
		
		do {
			i1++;
			st[i1]=getchar();
		} while (i1<STSIZE && st[i1]!='\n' );
		
		st[i1]='\0';

		if ((stc=operate_st(st, stv))==-1) {
			printf("Too mach parameters\n");
		}
		else {
			init_statistic();

			if(stc && operate_arg(stc, &stv[0])==1) {
				if (qt) {
					break;
				}
				else {	
					operate();
				}	
			}
			else if (hl) {
				printf("-h\t help\n");
				printf("-f [DISK:][PATH]FILENAME.csv\n\t file name\n");
				printf("-y\t year statictic\n");
				printf("-t MN|MD|SR|SS\n\t type of period:\n");
				printf("\t MN\t Midnight (from sunset to sunrise)\n");
				printf("\t MD\t Midday (from sunrise to sunset)\n");
				printf("\t SR\t Sunrise (from hour before sunrise two hours after sunrise)\n");
				printf("\t SS\t Sunset (from two hour befor sunset hour after sunset)\n");
				printf("-p BEGIN END\n\t specific period (from BEGIN hour to END hour)\n");
				printf("-m MONTH\n\t month statistic (other way year statistic)\n");
				printf("\t MONTH\t month number\n");
				printf("for example\n\n");
				printf("-m 2\n\n");
				printf("or\n\n");
				printf("-y\n\n");
				printf("or\n\n");
				printf("-p 1 5\n\n");
				printf("or\n\n");
				printf("-f temperature_big.csv\n");
				
			}		
		}	
	}		
}			

//-----
int operate_st(char *st, char *stv[]) {
	
	int np=0, sb=1, ln;//NUMBER PARAMETER, SKIP BLANC, LENGTH

	ln=strlen(st);

	for (int i=0;i<ln;i++) {
		if (sb) {//SKIP BLANC
			if (st[i]!=' ' || st[i]!='\t') {//BEGIN
				stv[np++]=&st[i];
				sb=0;
			}
		}
		else {
			if (st[i]==' ' || st[i]=='\t') {//END
				st[i]='\0';
				sb=1;
			}
		}
		if (np > STVSIZE) {
			return -1;
		}		
	}

	return np;
}

void print_statistic(void) {
	
	int dt1=to_date(im, 1, 0), dt2=to_date(im+1, 1, 0), curr, count=0;
	
	float middle_t=0, m1, m2;

	curr=find_data(dt1);
	
	printf("Date\tHour\tTemperature\tCount");

	do {
		middle_t+=hour_data[index[curr]].middle_t;
		count++;
		if (count==1) {
			m1=hour_data[index[curr]].middle_t;
			m2=hour_data[index[curr]].middle_t;
		}
		else {
		if (m1>hour_data[index[curr]].middle_t) m1=hour_data[index[curr]].middle_t;
		if (m2<hour_data[index[curr]].middle_t) m2=hour_data[index[curr]].middle_t;
		}	
		printf("%02d/%02d\t%02d\t%6.2f\t%d\n", to_month(hour_data[index[curr]].date), to_day(hour_data[index[curr]].date), to_hour(hour_data[index[curr]].date), hour_data[index[curr]].middle_t, hour_data[index[curr]].count);
		curr++;
	} while(hour_data[index[curr]].date<dt2 && curr<last);
	
	printf("Middle=%6.2f, Min=%6.2f, Max=%6.2f\n", middle_t/count, m1, m2);	
}
