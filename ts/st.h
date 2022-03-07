#include <stdint.h>

#define INSIZE 8784 //366*24
#define OUTSIZE 13 //12+1
#define MSIZE 4 

struct inst {
    uint16_t date;
    float t;
    uint16_t count;
};

struct outst {
    float middle_t;
    float max_t;
    float min_t;
    uint16_t count;
};

int hour(int);

int day(int);

int month(int);

uint16_t to_date(int, int, int);

int is_month(char*);

void init_data(void);

int read_data(char*);

int find_data(int);

void add_data(int*);

void sort_data(void);

void operate_data(int, int, int);

void set_sun_time(void);

int md(int, int);

int dm(int, int);

void set_statistic(struct outst*, int);
