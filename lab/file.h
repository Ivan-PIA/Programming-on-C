#include <stdio.h>
#define M 4
typedef struct line {
	int a;
	int b;

}line_t;

typedef struct point{
	int x;
	int y;
}point_t;

point_t init();
int count(point_t *c,line_t s);
