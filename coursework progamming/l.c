#include <stdlib.h>
#include <stdio.h>



int sum_numbers(int x){
    int n;
    if(x>0 && x<10)
        n=x%10;
    if (x>=10 && x<100)
        n=x%10+x/10%10;
    if (x>=100 && x<1000)
        n=x%10+x/10%10+x/100%10;
    if(x>=1000 && x<10000)
        n=x%10+x/10%10+x/100%10+x/1000%10;    
return n;    
}



int main(){
int x,result;
printf("Enter number: ");
scanf("%d",x);

result=sum_numbers(x);
printf("Sum of nubers: %d",result);


}