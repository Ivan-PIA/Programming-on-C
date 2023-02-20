#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void bubble_sort(int *mass, int N)
{
int tmp;
int c=0;
bool noSwap;

for (int i = N - 1; i >= 0; i--)
{
    noSwap = 1;
    for (int j = 0; j < i; j++)
    {
        if (mass[j] > mass[j + 1])
        {
            tmp = mass[j];
            mass[j] = mass[j + 1];
            mass[j + 1] = tmp;
            noSwap = 0;
        } 
        c+=1;
    }
    if (noSwap == 1){
        c+=1;
        break;}
}


}
int main(){

int a[4]={1,4,8,3};
int b[4]={5,3,7,1};
int c[8];
int k=0;

for(int i=0;i<4;i++){

c[k++]=a[i];
c[k++]=b[i];}
bubble_sort(c,8);
for(int i=0;i<8;i++)
printf("%d ",c[i]);
}