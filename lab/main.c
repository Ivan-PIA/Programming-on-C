#include "file.h"

int main(){

point_t g;

line_t s;

s.a=3;
s.b=4;

int i, sum=0;
point_t c[M];
printf("Введите координаты:\n");

for(i=0;i<M;i++){
printf("point №%d\n",i+1);
c[i]=init();
}


printf("Точек на прямой:%d", count(c,s));
}
