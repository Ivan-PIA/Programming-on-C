#include "file.h"

point_t init(point_t g){
	
	scanf("%d %d", &g.x,&g.y);
return g;
}


int count(point_t *c, line_t s){
	int sum=0;
	int i;
	for(i=0;i<M;i++){
		if (c[i].y==s.a*c[i].x+s.b)
			sum+=1;

	}
	return sum;
}
