#include <stdint.h>

#define INSIZE 8784 //366*24
#define OUTSIZE 13 //12+1
#define MSIZE 4 

struct inst {
    uint16_t date;
    int8_t t;
    uint16_t count;
};

struct outst {
    int8_t middle_t;
    int8_t max_t;
    int8_t min_t;
    uint16_t count;
};

int hour(int );

int day(int );

int month(int );

uint16_t to_date(int, int, int);

int is_month(char* );

void init_data(void );

int read_data(char* );

void operate_data(void );
