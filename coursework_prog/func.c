#include "head.h"


int sum_numbers(int x){
    int n=0;
    while(x/10!=0){
        n=n+x%10;
        x=x/10;
    }
    n+=x%10;
      
return n;    
}


int remarkable(int m,int n){
    int k,i;
    k=sum_numbers(m);
        
    if (m==pow(k,3))
        return m;
    else
        return -1;    

    

}

