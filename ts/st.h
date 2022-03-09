#include <stdint.h>

#define INSIZE 9000 //HOUR DATA
#define TESTSIZE 600000 //TEST LINE COUNT
#define STSIZE 200 //USER INTERFACE STRING
#define STVSIZE 10 //USER INTERFACE STRING VALUE

typedef struct inst {
    uint16_t date;
    float middle_t;
    int count;
} indt;

struct outst {
    float middle_t;
    float max_t;
    float min_t;
    int count;
};

int to_hour(int);

int to_day(int);

int to_month(int);

uint16_t to_date(int, int, int);

void init_statistic(void);

int read_data(void);

int find_data(int);

void add_data(int *);

void sort_data(void);

void operate_statistic(void);

void init_sun_time(void);

int md(int, int);

int dm(int, int);

void add_statistic(struct outst *, float);

int operate_arg(int, char *[]);

void operate(void);

void user_interface(void);

int operate_st(char *, char *[]);

void print_statistic(void);
